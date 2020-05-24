# get_next_line - @42Madrid
![MARK](https://bitbucket.org/estina/42madrid-get_next_line/raw/1897e629b39de834d9b863638af776d48bc1c627/mark.png)

------------

![Text](https://bitbucket.org/estina/42madrid-get_next_line/raw/1897e629b39de834d9b863638af776d48bc1c627/details.png)

------------

### 
* [What is get_next_line?](#what-is-get_next_line)
* [What we have there?](#what-we-have-there)

### What is get_next_line?

May it be a file, stdin, or even later a network connection, I will always need a way to read content line by line. It is time to start working on this function, which will be essential for my future projects.

### What we have there?

A function that reads a file descriptor and return a line when new line found or there is end of file. It is implemented using static variable to maintain data while the program runs.
A file with utils and a header file.

## [get_next_line](get_next_line/get_next_line.c)

```C
int	get_next_line(int fd, char **line)
```

Description | Param. #1 | Param. #2 | Return Value
:-----------: | :-----------: | :-----------: | :-----------: | :-----------:
Write a function which returns a line read from a file descriptor, without the newline | file descriptor for reading | The value of what has been read | 1 : A line has been read; 0 : EOF has been reached -1 : An error happened

[1]: https://www.42madrid.com/