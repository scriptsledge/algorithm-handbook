# AI Context & Instructions

**Project:** Algorithm Handbook
**User:** ScriptSledge (Pyzard)
**Goal:** Build a "Google-level" engineering resource for Data Structures & Algorithms.

## 🧠 Core Directives for AI

1.  **Professional Tone (Google Engineering Persona):**
    *   **Focus:** Trade-offs, Complexity, Scalability, Memory vs. Speed, Stability.
    *   **Avoid:** Generic "YouTuber" hype or "I tried this and failed" narratives.
    *   **Polls:** Use "Strategy" based polls (e.g., "Precomputation" vs "Greedy"), not "Success/Fail" polls.

2.  **File Architecture Enforcement:**
    *   **NEVER** create files manually if `scripts/scaffold.py` can be used.
    *   **ALWAYS** maintain the 5-file structure for new problems:
        1.  `solution.cpp`: C++ logic + `main()` test harness.
        2.  `discussion_post.md`: LeetCode post (Markdown). **NO circular links to the post itself.**
        3.  `social_media.md`: Metadata for YouTube, LinkedIn, and Meta.
        4.  `readme.md` (inside `src/`): GitHub landing page for the problem.
        5.  `docs/problems/XXXX.md`: Website documentation page.

3.  **Content Standards & Formatting:**

    *   **LeetCode Discussion (`discussion_post.md`):**
        *   Include `# 🏷️ LeetCode Submission Title` at the top.
        *   Do **not** link to the LeetCode post inside the body (circular dependency).

    *   **LinkedIn (`social_media.md`):**
        *   **Format:** Plain Text Only (No Markdown).
        *   **Structure:**
            1.  **Hook:** "How do you [Action] without [Constraint]?"
            2.  **Context:** Real-world engineering scenario (e.g., "In high-freq trading...").
            3.  **Goal:** One sentence problem statement.
            4.  **Solution:** "We use [Technique]..." (Step-by-step).
            5.  **Trade-off:** "We trade [Resource A] for [Resource B]."

    *   **Meta/Reels (`social_media.md`):**
        *   Include an **Engagement Poll** focused on engineering strategy.
        *   Plain Text Only.

    *   **YouTube (`social_media.md`):**
        *   Markdown is allowed (Bold, Italic, Links).

4.  **Interconnectivity:**
    *   Video -> GitHub & LeetCode.
    *   GitHub -> Video & LeetCode.
    *   LeetCode -> GitHub & Video.
    *   *Note:* Update links in `social_media.md` and `docs/` after posting.

5.  **Repository Details:**
    *   Repo: `github.com/scriptsledge/algorithm-handbook`
    *   Docs: `scriptsledge.github.io/algorithm-handbook`