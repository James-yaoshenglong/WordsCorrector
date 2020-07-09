# WordsCorrector
[1.0 中文版说明](#10-中文版)/[version1.0 English introduction](#version10-english-introduction)<br>
[2.0 中文版说明](#20-中文版)/[version2.0 English introduction](#version20-english-introduction)
# 1.0 中文版 
基于Levenshtein算法的词汇纠正器<br>
当前版本能够输入一个单词，如果错误能根据内置词汇表进行修改<br>
~~当前版本存在文件读写空间浪费以及大文件处理异常问题~~（在2.0版本中解决）<br>
2.0版本计划优化检测算法，以节约运行内存，~~并且添加直接处理整个文本文件的功能~~（在2.0版本中解决）和非法字符（如中文字符）的检测系统<br>

源代码：至commit 5

# 2.0 中文版
Linux命令行版本的词汇纠正器<br>
当前版本可以处理单个单词和文件，详细使用方法和说明见[README.md](./README.md)<br>
2.0版本还可以优化：
1. 节约FileCorrector类和SingalCorrector类中的重复代码（使用继承）
2. ~~在输出的修改提示中添加原文行号~~
3. 处理当前算法中大小写敏感的问题
4. 输出的文件名无法加括号的问题
5. 处理成对标点符号如(),''等的问题
6. 可以加入非英文字符检测
 
 源代码：至commit 14
 
# version1.0 English introduction
A words corrector programme based on Levenshtein Algorithm<br>
this version have the function to detect the correctness of an input word and correct it according the vocabulary in the programme<br>
~~this version have bug in wasting space for file IO and exception in dealing with big file~~(been solved in version 2.0)<br>
in version 2.0, I plan to optimize the algorithm to detect the word to save the memory cost.Moreover,I plan to add the function to ~~deal with a whole text file~~(been solved in version 2.0) and add a system to detect illegal characters like Chinese characters<br>

source code: until commit 5

# version2.0 English introduction
A command line words corrector on Linux OS<br>
Current version can deal with singal word and a whole file, detailed usage and introduction see [README.md](./README.md)<br>
version2.0 can be improved in below parts:
1. save the similar codes in FileCorrector class and SingalCorrector class(use inheritance)
2. ~~add line number in the output revision tips~~
3. solve the case sensitive problem in current algorithm
4. solve the problem that the output file name can not add ()
5. solve the problem that can not deal with punctuation in pairs like (), ''
6. add non English character check

source code: until commit 14