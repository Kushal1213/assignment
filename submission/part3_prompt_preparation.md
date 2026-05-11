 Part 3: Prompt Preparation

**Selected PR:** Beets — [PR #3883](https://github.com/beetbox/beets/pull/3883) — Preserve 'origin' field as a fixed metadata attribute.



3.1.1 Repository Context

Beets is an open-source media library management system designed for audiophiles and music collectors who need a centralized, programmatic way to organize their digital audio files. Written in Python, it serves as a sophisticated bridge between raw, often messy music files and a structured relational database. The repository's primary function is to automate the process of "tagging" music — syncing local metadata with global authorities like the MusicBrainz database. It handles file renaming, directory structuring, and metadata cleanup through a powerful command-line interface.

The intended users are individuals with large-scale music collections who require more precision than a standard media player can provide. These users often use Beets to enforce strict naming conventions and ensure that every track in their library contains accurate data regarding the artist, album, year, and genre. The problem domain it addresses is the inconsistency of digital media metadata. Music sourced from different platforms often lacks uniform tagging, making it difficult to search or sort.

Beets addresses this by utilizing SQLAlchemy to maintain a searchable SQLite database of all items. Its architecture is notably modular; while the core manages the database and basic file operations, a robust plugin system allows users to extend functionality to include tasks like fetching lyrics, calculating audio gain, or embedding album art. Ultimately, Beets transforms a chaotic folder of music into a high-integrity, queryable digital archive.

---

3.1.2 Pull Request Description

Pull Request #3883 introduces the "origin" metadata field as a first-class, fixed attribute within the Beets ecosystem. Before this PR, the system behavior regarding the provenance of a recording was inconsistent and often led to data loss. Many music collectors want to track where their files originated — for instance, whether a track was purchased from Bandcamp, sourced from a specific digital storefront, or came from a promotional distribution. While these files might have had an "origin" tag in their raw metadata (like ID3 tags), Beets did not have a dedicated column in its internal SQL database to store this specific information.

The **previous behavior** treated "origin" as a "flexible attribute." In Beets, flexible attributes are essentially "hidden" fields that are not indexed by default and are not consistently preserved during the import process unless specifically configured by the user.

The **new behavior** ensures that the importer explicitly scans for origin-related tags (such as `ORIGIN` or `SOURCEMEDIA`) and automatically maps them to the internal `origin` field. These changes are needed to ensure data parity between the physical music files and the Beets database.

Furthermore, the PR enables two-way synchronization: when a user manually updates the origin field via the CLI, the new logic ensures that the change is persisted in the database and written back into the audio file's physical tags, ensuring that the source information stays with the file even if it is moved outside of the Beets environment.

---

3.1.3 Acceptance Criteria

✓ When importing a file that contains an existing `ORIGIN` metadata tag, the value must be successfully saved to the Beets database and visible via `beet ls -f '$origin'`.

✓ The system should support a fallback mechanism where it checks multiple tag keys (e.g., `ORIGIN`, `SOURCE`, `SOURCEMEDIA`) and maps the first available one to the internal `origin` field.

✓ When a user executes `beet modify origin=NewSource`, the change must be persisted in the SQL database and immediately searchable via `beet ls origin:NewSource`.

✓ After running the `beet write` command, the internal `origin` value must be successfully synced back to the physical file's metadata tags (ID3v2 for MP3, Vorbis comments for FLAC).

✓ The implementation must handle files with no origin information gracefully by assigning a `None` value to the field without interrupting the import workflow.

✓ Existing databases must be automatically migrated to include the new `origin` column without requiring a manual SQL migration script from the user.

---

 3.1.4 Edge Cases

**Case 1: Conflicting Tags**
The model should consider how to handle a scenario where a file has both an `ORIGIN` and a `SOURCEMEDIA` tag with different values. The logic should define a clear priority order (e.g., `ORIGIN` takes precedence over `SOURCEMEDIA`) and document this behavior for the user.

**Case 2: Read-Only Filesystem**
If the library is stored on a read-only medium (like a CD-ROM or protected network share), the system must allow the `origin` field to be updated in the local database while catching and logging an `IOError` during the tag-writing phase. It should not crash the entire operation.

**Case 3: Character Encoding**
The system must handle non-ASCII or special characters (e.g., `"Bandcamp (Française)"`) in the origin field without causing database insertion errors or CLI display glitches. Proper UTF-8 handling must be enforced at the point of extraction and storage.

**Case 4: Large Library Performance**
For users with libraries exceeding 100,000 tracks, the initial schema migration to add the `origin` column must not create excessive blocking I/O. The migration should be validated against a large SQLite database to ensure it completes within an acceptable time.

---

## 3.1.5 Initial Prompt

> You are a Senior Python Developer working on the **Beets** music library manager (https://github.com/beetbox/beets). Your goal is to implement support for a new metadata field called `origin`, which tracks the source or distribution platform of a music file (e.g., "Bandcamp", "iTunes", "Promotional"). This requires making `origin` a standard, searchable, and persistent attribute in the library core, following the implementation pattern described in [PR #3883](https://github.com/beetbox/beets/pull/3883).
>
> ---
>
> **Repository Context:**
> Beets is a CLI-based music organizer that uses SQLAlchemy for its database layer. The core logic involves extracting tags from audio files (MP3, FLAC, OGG, etc.), optionally matching them with external databases like MusicBrainz, and storing all metadata in a local SQLite database. The `Item` class in `beets/library.py` defines the canonical database schema. Every recognized metadata field must be registered here. The `beets/mediafile.py` module handles the reading and writing of physical audio tags. The `beets/autotag/hooks.py` module maps raw tag data into Beets internal objects during import.
>
> ---
>
> **Tasks to Implement:**
>
> 1. **Database Schema Update**
>    Modify `beets/library.py` to add `origin` as a fixed attribute in the `Item` class. Define it as a `String` type using Beets' internal `types` system, consistent with how fields like `genre` or `comments` are defined. Ensure Beets' migration layer automatically adds this column to existing user databases.
>
> 2. **Metadata Extraction**
>    Update `beets/autotag/hooks.py`. Modify the mapping logic so that when the importer scans a file, it looks for raw tags such as `ORIGIN` or `SOURCEMEDIA` (in that priority order). These values should be assigned to the `ItemInfo` object's new `origin` attribute.
>
> 3. **CLI and Query Support**
>    Ensure the new field is registered so that users can query it interactively. A user should be able to run commands like:
>    - `beet ls origin:Bandcamp`
>    - `beet ls -f '$origin'`
>    - Use `$origin` in their `path_format` configuration in `config.yaml`
>
> 4. **Tag Synchronization (Round-Trip)**
>    Update the tag-writing logic in `beets/mediafile.py` to ensure that if the `origin` field is changed in the Beets database, it gets written back to the physical file's metadata tags during a `beet write` operation.
>
> ---
>
> **Technical Requirements:**
>
> - **Consistency:** Follow the existing architectural pattern of registered metadata fields. Do not introduce new patterns or abstractions beyond what is already present in `library.py`.
> - **Error Handling:** If a file resides on a read-only filesystem, the system must log a warning (not raise an unhandled exception) during the `beet write` phase and continue processing other files.
> - **Empty Values:** If a file has no source information in any of the recognized tag keys, the `origin` field should be set to `None` (SQL `NULL`) in the database without interrupting the import flow.
> - **Character Encoding:** All string handling must use UTF-8 encoding. Do not assume ASCII. Validate that special characters in the origin value (e.g., accented characters) are stored and retrieved without corruption.
>
> ---
>
> **Testing Requirements:**
>
> Create a new test file at `test/test_origin_metadata.py`. This file must contain tests that:
> - Mock an audio file object with an `ORIGIN` tag set to `"Bandcamp"`.
> - Pass the mock file through the importer pipeline.
> - Assert that the resulting library `Item` has `item.origin == "Bandcamp"`.
> - Execute a `beet modify origin=NewSource` equivalent and assert the change is reflected in the database.
> - Test that a file with **no** origin tag results in `item.origin is None`.
> - Test the conflict resolution: a file with both `ORIGIN` and `SOURCEMEDIA` tags should use the `ORIGIN` value.
>
> Please ensure the solution is fully backward compatible for users with existing databases. The column should be added to the schema automatically by Beets' internal migration system.

---

## Integrity Declaration

I declare that all written content in this assessment is my own work, created without the use of AI language models or automated writing tools. All technical analysis and documentation reflects my personal understanding and has been written in my own words.

kushal

