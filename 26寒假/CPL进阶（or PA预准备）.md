CPL后续进阶（仅部分C语言相关资料，更多请自行搜索）
subtitle：CPL（100-300行）--->PA（8k-2w行）中间还缺什么

1. [The Missing Semester of Your CS Education](https://missing.csail.mit.edu/): MIT Open Course，性价比最高的课程。主要讲授计算机系统相关的基础知识和工具使用方法，如交互式命令行（bash）、编辑器（vim）、版本控制（git）、调试（gdb）等内容。今年还为 AI Agentic Coding 单独开了一个课时。知识密度密度非常高，而且 PA 里立马就能用得上。不建议看中文版，不是最新版有滞后。

2. C Primer Plus、Modern C: 系统性的 C 语言入门书籍，内容全面且深入浅出。时间多可以快速翻阅一遍查漏补缺，时间少可以先记住目录，等用到的时候当字典看。

3. Pointers on C：指针查漏补缺

4. Fluent C: 进阶内容，讲述错误处理、内存管理、接口设计、模块化等背景下的 C 语言最佳实践，写出可读、可维护的代码。

5. The Art of Readable Code (Dustin Boswell and Trevor Foucher)
- 除了OJ正确性以外，写出更可读更可维护的代码是至关重要的！（也是当前CPL课程暂时缺少的，我们正在构建非功能指标Agent～）
- 永远值得去读读Glibc源码

6. 如果没上过SICP，可以去看看（更推荐听课https://sicp.pascal-lab.net/2025/）

7. 其他能够极大地提升学习及编码体验的知识点：
- Shell: 
  - 基本命令（ls、find、grep、wc、tee、tar 等）、重定向与管道（>、>>、<、|）、通配符（*、?、[]）、环境变量（$VAR）、命令替换（`command` 或 $(command)）、权限管理（chmod、chown）、进程管理（ps、top、kill）、压缩与归档（tar、zip、unzip）、文本处理工具（sed、awk）。以及他们的组合使用。
  - 简单脚本编写：变量、条件语句（if、case）、循环（for、while）。（再长的建议改用 AI+python 了）
  - The Art of Command Line： https://github.com/jlevy/the-art-of-command-line
  
- IDE: 不止于单文件，而是项目级的代码补全、语法高亮、调试工具、版本控制集成等功能，和构建系统结合获取头文件目录、宏定义等信息。
- C 语言特性：
  - 指针与内存管理: C 的内存模型（栈、堆），对象生命周期的概念、内存泄漏的检测与防止（sanitizer）。
  - 结构体与联合体: 内存中的布局、对齐，unnamed union、位域等进阶语法。
  - 错误处理: 使用 errno、perror 和自定义错误处理机制来处理运行时错误。
  - 元编程（宏）: 基本语法（define、if）、标识符拼接、字符串化、递归宏等。PA 会大量用到宏做条件编译和生成重复代码，会写新的宏也能在 PA 中让代码更简洁高效。[GNU 文档](https://gcc.gnu.org/onlinedocs/cpp/Macros.html) 和 [进阶技巧](https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms)

8. 常见各种工具可以在用到的时候再现查 manual。补充几个常用的：
- [Cppreference](https://en.cppreference.com/w/): C 和 C++ 标准库的权威参考手册，涵盖了所有标准库组件的详细说明、用法示例和性能特性。PA 里查标准库函数用法的首选。
- [TL;DR Pages](https://tldr.sh/): 提供常用命令行工具的简明扼要的使用说明和示例，适合快速查阅和学习常用命令的基本用法。
- [Explainshell](https://explainshell.com/): 解析复杂的 shell 命令，并逐部分解释每个开关的作用。（其实可以被 AI 取代了，放在这里的原因是它会给出每个开关原始的 man 说明，冷门命令会比 AI 准确一点）


