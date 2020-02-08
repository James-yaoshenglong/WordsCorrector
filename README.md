# WordsCorrector
[1.0 中文版说明](#10-中文版)/[version1.0 English introduction](#version10-english-introduction)

# 1.0 中文版 
基于Levenshtein算法的词汇纠正器<br>
当前版本能够输入一个单词，如果错误能根据内置词汇表进行修改<br>
当前版本存在文件读写空间浪费以及大文件处理异常问题<br>
2.0版本计划优化检测算法，以节约运行内存，并且添加直接处理整个文本文件的功能和非法字符（如中文字符）的检测系统<br>

[源代码](version1/main.cpp)

# version1.0 English introduction
A words corrector programme based on Levenshtein Algorithm<br>
this version have the function to detect the correctness of an input word and correct it according the vocabulary in the programme<br>
this version have bug in wasting space for file IO and exception in dealing with big file<br>
in version 2.0, I plan to optimize the algorithm to detect the word to save the memory cost.Moreover,I plan to add the function to deal with a whole text file and add a system to detect illegal characters like Chinese characters<br>

[source code](version1/main.cpp)


