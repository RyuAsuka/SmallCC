echo off
cls
echo 程序1：输入两个整数，求它们的最大公约数
pause > nul
smallcc test1.txt test1out.txt
pause > nul
echo -s选项：可以查看数据栈；-l选项，可以单步查看指令
pause > nul
smallint test1out.txt -s -l
pause > nul
echo 程序1不带选项的执行版本
pause > nul
smallint test1out.txt
pause > nul
echo 查看smallint程序帮助
pause > nul
smallint -help
pause > nul
echo 程序2：输出1-100以内的素数
pause > nul
smallcc test2.txt test2out.txt
echo 执行：
pause > nul
smallint test2out.txt
echo 程序3：测试逻辑运算
pause > nul
smallcc test3.txt test3out.txt
echo 执行：
pause > nul
smallint test3out.txt
echo 程序4：错误处理
pause > nul
smallcc bugtest.txt bugtestout.txt
pause > nul
echo on
pause
