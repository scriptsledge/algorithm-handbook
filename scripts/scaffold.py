import os
import sys
import argparse

# Configuration
ROOT_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_DIR = os.path.join(ROOT_DIR, 'src')
DOCS_DIR = os.path.join(ROOT_DIR, 'docs', 'problems')
MKDOCS_FILE = os.path.join(ROOT_DIR, 'mkdocs.yml')

# Templates
CPP_TEMPLATE = """#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // TODO: Copy function signature from LeetCode
};

int main() {
    Solution sol;
    // TODO: Add test cases
    cout << "Test passed!" << endl;
    return 0;
}
"""

SUBMISSION_TEMPLATE = """# 🚀 Intuition
<!-- Describe your first thoughts here -->

# 💡 Approach
<!-- Describe your algorithm here -->

# 🎥 Video Explanation
[**Watch the quick walkthrough on YouTube**](YOUR_YOUTUBE_LINK_HERE)

# 💻 Complexity
*   **Time complexity:** $$O(N)$$
    <!-- Explanation -->
*   **Space complexity:** $$O(N)$$
    <!-- Explanation -->

# 👨‍💻 Code
```cpp
// Paste your solution class here
```

---
**Connect & Follow:**
*   📘 **Algorithm Handbook:** [Source Code & Docs](https://github.com/scriptsledge/algorithm-handbook/tree/main/src/{number})
*   💡 **LeetCode Solution:** [View on LeetCode](YOUR_LEETCODE_POST_LINK)
"""

METADATA_TEMPLATE = """# Video Metadata - Problem {number}

## 📺 YouTube (Markdown Supported)

**Title:** LeetCode {number}: {title} | C++ Solution

**Description:**
<!-- Add concise engineering description -->

*📊 Complexity Analysis*
- Time: O(N)
- Space: O(N)

*👇 Resources & Code*
📘 Algorithm Handbook (Source Code):
https://github.com/scriptsledge/algorithm-handbook/tree/main/src/{number}

💡 Detailed Article (LeetCode):
YOUR_LEETCODE_POST_LINK

#LeetCode #Algorithms #Cpp #DataStructures #SoftwareEngineering #CodingInterview

---

## 📸 Meta (Facebook/Instagram - Plain Text)

**Caption:**
LeetCode {number}: {title} | C++ Solution 🚀

<!-- Add concise engineering description -->

📊 Complexity Analysis:
- Time: O(N)
- Space: O(N)

🔗 Resources & Code:
Find the full source code and detailed article here:
https://github.com/scriptsledge/algorithm-handbook/tree/main/src/{number}

#LeetCode #Algorithms #Cpp #DataStructures #SoftwareEngineering #CodingInterview #CodingLife #Programming #TechTips

---

## 💼 LinkedIn Post (Professional Tone)

**Headline:** Stability in Array Processing: A Linear Time Approach 🚀

Rearranging data is trivial. Preserving the **relative order** of elements while doing it? That's an engineering challenge.

In today's LeetCode breakdown (**Problem {number}: {title}**), we explore how to alternate positive and negative integers in O(N) time without disrupting their original sequence.

**The Engineering Trade-off:**
To maintain stability, we sacrifice O(1) space for O(N) space. In production systems, predictability often trumps raw memory optimization.

**💡 Key Takeaways:**
✅ Two-Pointer Technique
✅ Stable Sorting Principles
✅ Clean C++ Implementation

**Read the full analysis in the Handbook:**
👉 https://scriptsledge.github.io/algorithm-handbook/problems/{number}/

#SoftwareEngineering #DataStructures #Cpp #LeetCode #CareerGrowth #Tech
"""

DOCS_TEMPLATE = """---
title: {number}. {title}
tags:
  - TODO_TAG
  - Medium
---

# {number}. {title}

<div class="grid cards" markdown>

-   :material-youtube: **Watch the Solution**
    [Coming Soon](#){{ .md-button }}

-   :material-github: **View on GitHub**
    [Source Code](https://github.com/scriptsledge/algorithm-handbook/tree/main/src/{number}){{ .md-button }}

-   :simple-leetcode: **LeetCode Solution**
    [Solve It](https://leetcode.com/problems/TODO-SLUG/){{ .md-button }}

</div>

## 📝 Problem Description

!!! info "Problem Statement"
    <!-- Paste problem description here -->

### Examples
<!-- Paste examples here -->

### Constraints
<!-- Paste constraints here -->

## 🧠 Intuition

<!-- Add intuition here -->

## 💡 Approach

<!-- Add approach here -->

## 💻 Code

=== "C++"

    ```cpp
    --8<-- "src/{number}/solution.cpp"
    ```

## 📊 Complexity Analysis

*   **Time Complexity:** $O(N)$
    <!-- Explanation -->

*   **Space Complexity:** $O(N)$
    <!-- Explanation -->
"""

def create_problem(number, title):
    # 1. Create Directories
    prob_dir = os.path.join(SRC_DIR, number)
    if os.path.exists(prob_dir):
        print(f"❌ Error: Problem {number} already exists.")
        return
    
    os.makedirs(prob_dir)
    print(f"✅ Created directory: src/{number}")

    # 2. Create Source Files
    with open(os.path.join(prob_dir, "solution.cpp"), "w") as f:
        f.write(CPP_TEMPLATE)
    
    with open(os.path.join(prob_dir, "discussion_post.md"), "w") as f:
        f.write(SUBMISSION_TEMPLATE.format(number=number))

    with open(os.path.join(prob_dir, "social_media.md"), "w") as f:
        f.write(METADATA_TEMPLATE.format(number=number, title=title))
        
    print(f"✅ Created templates in src/{number}/")

    # 3. Create Documentation File
    doc_path = os.path.join(DOCS_DIR, f"{number}.md")
    with open(doc_path, "w") as f:
        f.write(DOCS_TEMPLATE.format(number=number, title=title))
    print(f"✅ Created docs: docs/problems/{number}.md")

    # 4. Update mkdocs.yml
    update_mkdocs_nav(number, title)

def update_mkdocs_nav(number, title):
    with open(MKDOCS_FILE, "r") as f:
        lines = f.readlines()
    
    # Find the "Problems:" line
    insert_idx = -1
    for i, line in enumerate(lines):
        if "- Problems:" in line:
            insert_idx = i + 1
            break
    
    if insert_idx != -1:
        new_entry = f"      - '{number}. {title}': problems/{number}.md\n"
        lines.insert(insert_idx, new_entry)
        
        with open(MKDOCS_FILE, "w") as f:
            f.writelines(lines)
        print(f"✅ Added to mkdocs.yml navigation")
    else:
        print("⚠️ Warning: Could not find '- Problems:' section in mkdocs.yml")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python3 scaffold.py <number> <title>")
        print("Example: python3 scaffold.py 0001 \"Two Sum\"")
        sys.exit(1)
    
    number = sys.argv[1]
    title = " ".join(sys.argv[2:])
    
    create_problem(number, title)
