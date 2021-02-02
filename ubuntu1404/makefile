#把所有的目录做成变量，方便修改和移植   
#教训：不要在一个变量中定义多个路径 ，但是可以在一
#个变量中放置多个变量的值
#可以用 echo来帮助调试写的 makefile文件

#定义路径变量
SERIAL =./serial
OBJ =./obj

#定义指定头文件路径参数 和 gcc编译参数 及 可执行文件
CC = gcc   
INC =-Iserial
CFLAGS = -g -Wall ${INC}
BIN_TARGET = test

# 获取要求中工作目录下的所有的.c文件列表
SRC =$(wildcard ${SERIAL}/*.c)\
	 $(wildcard *.c)

# 通过替换获取所有目标文件名并放在obj/目录下  
OBJECT =$(patsubst %.c,${OBJ}/%.o,$(notdir ${SRC}))  

#可以用 echo来帮助调试写的 makefile文件
#all:
	#@echo "start debug!"
	#@echo ${SRC}
	#@echo ${OBJECT}  

#用 *.o生成可执行文件test，其中可用 $^替换掉 ${OBJECT}  
${BIN_TARGET}:${OBJECT}  
	$(CC) $(CFLAGS) -o $@ ${OBJECT}  

#在相应目录下依次将对应源文件生成对应目标文件  
${OBJ}/%.o:${SERIAL}/%.c   
	$(CC) -c $< -o $@ 
${OBJ}/%.o:./%.c   
	$(CC) $(CFLAGS) -c $< -o $@ 


#删除文件
.PHONY:clean  
clean:  
	# -exec 后面接执行命令
	# rm -rf {}命令就是删除文件 
	# \;这是格式要求的没有具体含义。
	# 嵌套执行make命令如下：
	# ${MAKE} -C +目录名(含有makefile文件的子目录)等价于 先cd到 目录名/ 再执行make命令  
	# ${MAKE} clean -C +目录名(含有makefile文件的子目录)等价于 先cd到 目录名/ 再执行make clean 命令 
	find $(OBJ) -name *.o -exec rm -rf {} \; 
	rm -rf test a.out *.o 
	#${MAKE} clean -C serial
