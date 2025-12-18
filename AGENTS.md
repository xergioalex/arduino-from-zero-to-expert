# AGENTS.md - Documentation for AI Agents

**Purpose:** This file is the **single source of truth** for all AI coding assistants working with this repository, including:
- **Claude Code** (via `CLAUDE.md` import using `@AGENTS.md`)
- **Cursor AI** (can reference this file directly)
- **OpenAI Codex (ChatGPT)**
- **Google Gemini (Antigravity)**
- **GitHub Copilot**
- **Other AI coding assistants**

This ensures all agents work in harmony with consistent guidelines, coding standards, and architectural patterns.

## Project Overview

**Arduino From Zero to Expert** is a learning repository for Arduino programming. It contains Arduino projects, scripts, examples, tutorials, and educational content to help users learn Arduino from basics to advanced topics.

**Technology Stack:**
- **Arduino** - Microcontroller programming
- **C/C++** - Arduino programming language
- **Python** (optional) - Utility scripts and tools
- **Markdown** - Documentation and tutorials

## Project Structure

```
arduino-from-zero-to-expert/
├── projects/          # Arduino projects and examples
├── scripts/           # Utility scripts (Python, shell, etc.)
├── docs/              # Documentation and tutorials
├── examples/          # Code examples and snippets
└── README.md          # Main project documentation
```

## CRITICAL: Mandatory Requirements

### 1. Language Standards

**ALL code, comments, and documentation MUST be in English.**

✅ Code, comments, docs, commits, variable names in English
❌ Never use Spanish or any other language

**Always update documentation after important changes.**

### 2. Code Style Standards

#### Arduino/C++ Code Style

- Use clear, descriptive variable and function names
- Follow Arduino naming conventions (camelCase for variables, PascalCase for classes)
- Add comments explaining complex logic
- Organize code with proper indentation (2 spaces recommended)
- Include header comments with project description, author, and date

**Example:**
```cpp
/*
 * Project: LED Blink Example
 * Description: Simple example to blink an LED
 * Author: Your Name
 * Date: 2024
 */

const int LED_PIN = 13;  // Built-in LED pin

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
```

#### Python Code Style (if using Python scripts)

**Import Order Convention (MANDATORY):**

Follow this import order in all Python files:

```python
# 1. Python native packages
import os
from typing import Optional, List

# 2. Third party packages
import serial
import numpy as np

# 3. Internal project packages
from utils.helpers import HelperClass
```

**Type Hints (MANDATORY):**

**ALL Python code MUST use type hints:**

**CRITICAL FOR CODE GENERATION**: When generating new code, ALWAYS include complete type hints for:
- All function parameters
- All return types
- All variable assignments
- All class attributes
- Lambda functions where applicable

```python
from typing import Optional, List, Dict, Any

# ✅ CORRECT - Generated code must include all type hints
def process_data(data: List[Dict[str, Any]], sensor_id: int) -> bool:
    result: bool = validate_data(data)
    return result

# ❌ INCORRECT - Never generate code without type hints
def process_data(data, sensor_id):
    result = validate_data(data)
    return result
```

**If you generate code without type hints, you MUST add them before the code is complete.**

### 3. Test File Naming (if using tests)

✅ **ALWAYS use `*_test.py`**: `sensor_test.py`, `utils_test.py`
❌ **NEVER use `test_*.py`**: Not configured in standard test runners

## Shared Agent Coordination - CRITICAL

**Multiple AI agents collaborate:**
1. **Cursor AI** - Guided by `.cursorrules`
2. **Claude Code** - Guided by `CLAUDE.md`
3. **OpenAI Codex (ChatGPT)** - Guided by this file (`AGENTS.md`)
4. **Google Gemini (Antigravity)** - Guided by this file (`AGENTS.md`)

**MANDATORY SYNCHRONIZATION**: When updating one file, mirror changes in other two.

**Synchronize**: Patterns, standards, architectural practices, common mistakes
**Don't sync**: Agent-specific workflows

## Documentation Standards

### Documentation Structure (MANDATORY)

All projects and functionalities MUST follow this documentation structure:

```
projects/myproject/
├── README.md                    # ← MANDATORY: General overview and complete documentation
├── docs/                        # ← MANDATORY: Detailed documentation folder (if needed)
│   ├── README.md                # ← MANDATORY: Index of all documentation in this folder
│   ├── SETUP.md                 # Setup instructions
│   ├── CIRCUIT.md               # Circuit diagram and connections
│   ├── CODE.md                  # Code explanation
│   └── ...
├── src/                         # Source code
│   └── myproject.ino
├── schematics/                  # Circuit diagrams
└── README.md
```

**Requirements:**
- ✅ **README.md** at project root: General overview, key features, quick start, circuit connections, code explanation
- ✅ **docs/** folder: Contains all detailed documentation files (when needed)
- ✅ **docs/README.md**: Index/navigation guide listing all documentation files in the folder
- ✅ Each detailed doc file covers a specific aspect (setup, circuit, code, troubleshooting, etc.)

**When to update documentation:**
- ✅ After adding new projects or features
- ✅ After changing the project structure or build process
- ✅ After establishing new patterns or fixing critical bugs
- ✅ After adding new examples or tutorials

### Documentation Content Guidelines

**Every project README.md should include:**

1. **Project Title and Description**
   - What the project does
   - Learning objectives
   - Difficulty level (beginner/intermediate/advanced)

2. **Components Required**
   - List of hardware components
   - Arduino board type
   - Any additional modules or sensors

3. **Circuit Diagram**
   - Visual representation or detailed connection instructions
   - Pin assignments clearly labeled

4. **Code Explanation**
   - Overview of how the code works
   - Key functions and their purpose
   - Important concepts demonstrated

5. **Usage Instructions**
   - Step-by-step setup guide
   - How to upload and run the code
   - Expected behavior

6. **Troubleshooting**
   - Common issues and solutions
   - Tips for debugging

## Common Mistakes to Avoid

### ❌ DON'T:
1. Write code/docs in Spanish (English only)
2. Skip documentation updates
3. Write Python without type hints (MANDATORY for Python)
4. **Generate code without type hints** - ALWAYS include typing in generated Python code
5. Use `test_*.py` naming (use `*_test.py` if using tests)
6. Skip import order convention (for Python)
7. Use unclear variable names (e.g., `x`, `temp`, `data`)
8. Skip comments in complex Arduino code
9. Forget to document pin connections
10. Create projects without README.md
11. Use hardcoded values without constants
12. Skip error handling in Python scripts

### ✅ DO:
1. Write all code in English
2. Update docs after important changes
3. ALWAYS use type hints in Python (MANDATORY)
4. **ALWAYS include typing in generated Python code** - Every function, parameter, return value, and variable must have type hints when generating new code
5. Name tests `*_test.py` (if using tests)
6. Follow import order: native → third-party → internal (for Python)
7. Use descriptive variable names (e.g., `ledPin`, `sensorValue`, `buttonState`)
8. Add comments explaining complex logic
9. Document all pin connections clearly
10. Include comprehensive README.md for each project
11. Use named constants instead of magic numbers
12. Include error handling in Python scripts
13. Follow Arduino coding conventions
14. Organize code with proper structure (setup, loop, helper functions)

## Pre-Commit Checklist

- [ ] All code in English with proper naming
- [ ] **All generated Python code includes complete type hints** (functions, parameters, returns, variables, class attributes)
- [ ] Documentation updated if needed
- [ ] Test files use `*_test.py` naming (if applicable)
- [ ] Import order follows convention (for Python)
- [ ] Code follows style guidelines
- [ ] README.md includes all required sections
- [ ] Pin connections are clearly documented
- [ ] Comments explain complex logic
- [ ] Commit message in English (conventional format)

## Conventional Commits

**Format**: `<type>: <description>`

**Types**: `feat`, `fix`, `docs`, `style`, `refactor`, `test`, `chore`, `perf`, `ci`

**Examples:**
- `feat: add LED blink example project`
- `fix: correct pin assignment in sensor example`
- `docs: update project README with circuit diagram`
- `test: add unit tests for serial communication utility`
- `chore: organize examples folder structure`

## Quick Reference Links

### External Resources
- [Arduino Official Documentation](https://www.arduino.cc/reference/en/)
- [Arduino IDE Guide](https://www.arduino.cc/en/guide)
- [Arduino Language Reference](https://www.arduino.cc/reference/en/)
- [Python Documentation](https://docs.python.org/3/) (if using Python scripts)
