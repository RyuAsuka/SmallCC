echo off
cls
echo ����1���������������������ǵ����Լ��
pause > nul
smallcc test1.txt test1out.txt
pause > nul
echo -sѡ����Բ鿴����ջ��-lѡ����Ե����鿴ָ��
pause > nul
smallint test1out.txt -s -l
pause > nul
echo ����1����ѡ���ִ�а汾
pause > nul
smallint test1out.txt
pause > nul
echo �鿴smallint�������
pause > nul
smallint -help
pause > nul
echo ����2�����1-100���ڵ�����
pause > nul
smallcc test2.txt test2out.txt
echo ִ�У�
pause > nul
smallint test2out.txt
echo ����3�������߼�����
pause > nul
smallcc test3.txt test3out.txt
echo ִ�У�
pause > nul
smallint test3out.txt
echo ����4��������
pause > nul
smallcc bugtest.txt bugtestout.txt
pause > nul
echo on
pause
