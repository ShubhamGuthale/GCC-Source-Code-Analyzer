# 🧠 GCC Source Code Analyzer – C File Keyword & Symbol Counter

A C-based tool that recursively scans and analyzes **GCC source code files** to count:
- 🔑 C language **keywords**
- 🔣 Special **symbols**
- 📄 Appends analysis results to a `README.md` report

This utility helps in performing **static analysis** on large codebases like the GCC compiler source to identify usage patterns of language constructs.

---

## 🎯 Features

- ✅ Analyze `.c` files from the GCC source directory
- ✅ Count C **keywords** (like `if`, `while`, `int`, etc.)
- ✅ Count **special characters** (`{}`, `;`, `#`, etc.)
- ✅ Generate and update `README.md` with results
- ✅ Works recursively across all files in a directory

---

## 🛠️ Tech Stack

| Component         | Technology          |
|------------------|---------------------|
| Language          | C (GCC Compatible)  |
| Platform          | Linux / Windows     |
| Editor Support    | VS Code, Notepad++, Sublime |
| Dependencies      | GCC (for compilation) |
| Output Format     | Markdown (`README.md`) |


---

## 📥 Prerequisites

- 🧱 GCC installed on your system
- 📁 Access to downloaded GCC source code (example: `/home/user/gcc-source/`)
- 🧑‍💻 Any code editor (VS Code recommended)


---

## 📝 Sample Screenshot

<img width="960" alt="Screenshot 2024-01-14 102622" src="https://github.com/ShubhamGuthale/Implementation-Of-GCC-Analyzer/assets/150772720/ea4fb951-dd9a-4384-8ff7-71c9eb100f10">


---

## 🚀 How to Run

### ✅ 1. Save and Compile

Save your file as `analyze.c` or any `.c` filename.

```bash
gcc analyze.c -o analyzer

