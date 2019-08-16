# Data Manager
This is a simple C based console application that allows you to add records to a static (predefined) table. It's possible to change data, print table or part thereof, search by column, delete records, sort by column, save and open from a file. This project has created for porpose of university practice after half of a year after I started my studying as a Computer Engineer, so I apologize for lack of comments.

## Table of contents
* [I have learned](#i-have-learned)
* [Technologies](#technologies)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installing](#installing)
* [Built With](#built-with)

| [![](https://i.ibb.co/ZVybbwT/C-work-C-Practive-first-year-Data-Manager-Debug-Data-Manager-exe-8-16-2019-7-05-45-AM.png)](https://i.ibb.co/ZVybbwT/C-work-C-Practive-first-year-Data-Manager-Debug-Data-Manager-exe-8-16-2019-7-05-45-AM.png)  | [![](https://i.ibb.co/JChSHFf/C-work-C-Practive-first-year-Data-Manager-Debug-Data-Manager-exe-8-16-2019-7-10-50-AM.png)](https://i.ibb.co/JChSHFf/C-work-C-Practive-first-year-Data-Manager-Debug-Data-Manager-exe-8-16-2019-7-10-50-AM.png) |
|:---:|:---:|

## I have learned

- Splitting program into functions;
- User input processing;
- Working with strings;
- Dealing with pointers;
- Getting and saving data to a file;

## Technologies
- C

## Getting Started
If you want to run the program or change the code, firstly, you will need to copy the entire repository.
Open bash, go to the folder where you would like to store files and write:
```
git clone https://github.com/Vidzhel/data_manager.git
```

Then if you want, you can simply run the program with [file Debug/DataManager.exe](Debug/DataManager.exe) or you can rewrite the program. To do that open [file DataManager.sln](DataManager.sln) with [Visual Studio 2019](https://visualstudio.microsoft.com/vs/). If you are using Visual Studio 2017, then you need to uncomment the first row:
```
//#include "pch.h"
```

**Note:** do not use "Enter" to input string instead use dot ".".

### Prerequisites
If you want to just run the program, then you don't need any software (OS Windows) just run [file Debug/DataManager.exe](Debug/DataManager.exe). Otherwise, you need to install the [Visual Studio 2019](https://visualstudio.microsoft.com/vs/) community version, it's free.

## Built With
- Visual Studio 2017 - IDE
