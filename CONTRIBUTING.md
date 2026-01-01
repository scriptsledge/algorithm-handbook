# Engineering Standards & Workflow Guide

## 1. Philosophy
This repository follows the **Separation of Concerns** principle to ensure scalability and maintainability.
*   **Logic (`src/`)**: Pure code. No marketing fluff.
*   **Presentation (`docs/`)**: The educational content for the website.
*   **Distribution (`social_media.md`)**: Marketing assets for external platforms.

## 2. Naming Conventions (Google Style)
We adhere to strict naming to ensure predictability.

| Type | Convention | Example |
| :--- | :--- | :--- |
| **Directories** | 4-Digit ID | `src/0001/` |
| **Source Files** | snake_case | `solution.cpp` |
| **Documentation** | snake_case | `discussion_post.md`, `social_media.md` |
| **Web Pages** | ID.md | `docs/problems/0001.md` |

## 3. Directory Structure
```text
algorithm-handbook/
├── docs/problems/       # Website Content (Markdown)
│   └── 0001.md          # Imports code from src/
├── scripts/             # Automation Tools
│   └── scaffold.py      # Generates new problem files
└── src/                 # The Source of Truth
    └── 0001/
        ├── solution.cpp       # The Code (C++)
        ├── discussion_post.md # For LeetCode "Solutions" Tab
        └── social_media.md    # For YouTube/Instagram Metadata
```

## 4. Daily Workflow

### Step 1: Scaffold
Generate the file structure instantly.
```bash
python3 scripts/scaffold.py <ID> "<Title>"
# Example: python3 scripts/scaffold.py 0001 "Two Sum"
```

### Step 2: Implementation
*   **Solve:** Write code in `src/XXXX/solution.cpp`.
*   **Verify:** Run the code locally to ensure correctness.

### Step 3: Documentation
*   **Website:** Edit `docs/problems/XXXX.md`. Add "Intuition" and "Approach".
*   **LeetCode:** Fill `src/XXXX/discussion_post.md` (Copy intuition/approach).
*   **Socials:** Update `src/XXXX/social_media.md` (Add Title, SEO Description).

### Step 4: Distribution
*   **Record:** Create your video.
*   **Upload:** Use content from `social_media.md` and `discussion_post.md` to populate YouTube, Instagram, and LeetCode.

### Step 5: Publish
```bash
git add .
git commit -m "feat: add solution for XXXX"
git push
```
