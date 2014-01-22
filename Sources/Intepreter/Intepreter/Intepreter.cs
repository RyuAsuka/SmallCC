using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Linq;

namespace Intepreter
{
    /// <summary>
    /// 中间代码的指令
    /// </summary>
    struct Instruction
    {
        /// <summary>
        /// 操作码
        /// </summary>
        public string OpCode;
        /// <summary>
        /// 操作数
        /// </summary>
        public string Operand;
    }

    /// <summary>
    /// 标号
    /// </summary>
    struct Label
    {
        /// <summary>
        /// 标号名
        /// </summary>
        public string Name;
        /// <summary>
        /// 标号所在程序地址
        /// </summary>
        public int Address;
    }

    /// <summary>
    /// 解释器
    /// </summary>
    public class Intepreter
    {
        private readonly StreamReader sr;
        private int pc;
        private bool flag;
        private readonly Regex identifierRegex = new Regex("[A-Za-z]([A-Za-z]|[0-9])*");
        private readonly Regex numberRegex = new Regex("[0-9]+");
        private readonly Table table;
        private readonly int[] dataStack;
        private int top;
        private readonly List<Instruction> instructionList;
        private readonly List<Label> labelTable;

        /// <summary>
        /// 构造方法
        /// </summary>
        /// <param name="path">文件所在路径</param>
        public Intepreter(string path)
        {
            sr = new StreamReader(path);
            pc = 0;
            flag = false;
            table = new Table();
            dataStack = new int[500];
            top = -1;
            instructionList = new List<Instruction>();
            labelTable = new List<Label>();
        }

        /// <summary>
        /// 将编译器生成的中间代码读入，在内存中产生“指令”
        /// </summary>
        public void GenerateCode()
        {
            int codeNo = 0;
            while (!sr.EndOfStream)
            {
                var codeString = sr.ReadLine();
                if (codeString != null)
                {
                    var code = codeString.Split(new[] { ' ', '\t' });
                    Instruction c;
                    switch (code.Count())
                    {
                        case 2:
                            c = new Instruction { OpCode = code[0], Operand = code[1] };
                            instructionList.Add(c);
                            codeNo++;
                            break;
                        case 1:
                            if (code[0][0] == 'L')
                            {
                                var l = new Label { Name = code[0].Substring(0, 4), Address = codeNo };
                                labelTable.Add(l);
                                c = new Instruction { OpCode = code[0], Operand = "NULL" };
                                instructionList.Add(c);
                                codeNo++;
                            }
                            else
                            {
                                c = new Instruction { OpCode = code[0], Operand = "NULL" };
                                instructionList.Add(c);
                                codeNo++;
                            }
                            break;
                    }
                }
            }
        }

        /// <summary>
        /// 执行指令
        /// </summary>
        /// <param name="switchs">传入的开关参数：1-是否显示堆栈，2-是否显示指令</param>
        public void ExecuteCode(bool[] switchs)
        {
            pc = 0;
            string tempId = string.Empty;
            while (pc < instructionList.Count)
            {
                Instruction ins = instructionList[pc];
                if (switchs[1])
                {
                    Console.WriteLine("{0} {1}", ins.OpCode, ins.Operand);
                    Console.ReadLine();
                }
                int address;

                switch (ins.OpCode)
                {
                    case "push":
                        if (identifierRegex.IsMatch(ins.Operand))
                        {
                            dataStack[++top] = table.GetValue(ins.Operand);
                            tempId = ins.Operand;
                        }
                        else if (numberRegex.IsMatch(ins.Operand))
                        {
                            dataStack[++top] = Convert.ToInt32(ins.Operand);
                        }
                        pc++;
                        break;
                    case "pop":
                        if (identifierRegex.IsMatch(ins.Operand))
                        {
                            table.SetValue(ins.Operand, dataStack[top], RunTimeType.Var);
                        }
                        top--;
                        pc++;
                        break;
                    case "new":
                        if (identifierRegex.IsMatch(ins.Operand))
                            table.EnterTable(new TableItem { Name = ins.Operand, Value = ++top, Type = RunTimeType.Array });
                        pc++;
                        break;
                    case "alloc":
                        for (; top < Convert.ToInt32(ins.Operand); top++)
                            dataStack[top] = -1;
                        pc++;
                        break;
                    case "stm":
                        address = table.GetValue(ins.Operand);
                        dataStack[address + dataStack[top - 1]] = dataStack[top];
                        top -= 3;
                        pc++;
                        break;
                    case "ldm":
                        address = table.GetValue(ins.Operand);
                        dataStack[top-1] = dataStack[address + dataStack[top]];
                        pc++;
                        top--;
                        break;
                    case "jz":
                        if (!flag)
                            pc = labelTable[labelTable.FindIndex(item => item.Name == ins.Operand)].Address;
                        else pc++;
                        top--;
                        break;
                    case "jmp":
                        pc = labelTable[labelTable.FindIndex(item => item.Name == ins.Operand)].Address;
                        break;
                    case "out":
                        Console.WriteLine("{0}", dataStack[top]);
                        pc++;
                        top--;
                        break;
                    case "in":
                        string svar;
                        do 
                        {
                            Console.Write("{0}? ", ins.Operand);
                        } while ((svar = Console.ReadLine())=="");
                        int input = Convert.ToInt32(svar);
                        table.SetValue(ins.Operand, input, RunTimeType.Var);
                        pc++;
                        top--;
                        break;
                    case "odd":
                        flag = dataStack[top] % 2 != 0;
                        top--;
                        break;
                    case "mod":
                        dataStack[top - 1] %= dataStack[top];
                        top--;
                        pc++;
                        break;
                    case "neg":
                        dataStack[top] = -dataStack[top];
                        pc++;
                        break;
                    case "add":
                        dataStack[top - 1] += dataStack[top];
                        top--;
                        pc++;
                        break;
                    case "sub":
                        dataStack[top - 1] -= dataStack[top];
                        top--;
                        pc++;
                        break;
                    case "mul":
                        dataStack[top - 1] *= dataStack[top];
                        top--;
                        pc++;
                        break;
                    case "div":
                        dataStack[top - 1] /= dataStack[top];
                        top--;
                        pc++;
                        break;
                    case "compLT":
                        flag = dataStack[top - 1] < dataStack[top];
                        top -= 2;
                        dataStack[++top] = flag ? 1 : 0;
                        pc++;
                        break;
                    case "compGT":
                        flag = dataStack[top - 1] > dataStack[top];
                        top -= 2;
                        dataStack[++top] = flag ? 1 : 0;
                        pc++;
                        break;
                    case "compLE":
                        flag = dataStack[top - 1] <= dataStack[top];
                        top -= 2;
                        dataStack[++top] = flag ? 1 : 0;
                        pc++;
                        break;
                    case "compGE":
                        flag = dataStack[top - 1] >= dataStack[top];
                        top -= 2;
                        dataStack[++top] = flag ? 1 : 0;
                        pc++;
                        break;
                    case "compEQ":
                        flag = dataStack[top - 1] == dataStack[top];
                        top -= 2;
                        dataStack[++top] = flag ? 1 : 0;
                        pc++;
                        break;
                    case "compNE":
                        flag = dataStack[top - 1] != dataStack[top];
                        top -= 2;
                        dataStack[++top] = flag ? 1 : 0;
                        pc++;
                        break;
                    case "and":
                        dataStack[top] = dataStack[top - 1] & dataStack[top];
                        flag = dataStack[top] != 0;
                        top--;
                        pc++;
                        break;
                    case "or":
                        dataStack[top] = dataStack[top - 1] | dataStack[top];
                        flag = dataStack[top] != 0;
                        top--;
                        pc++;
                        break;
                    case "not":
                        dataStack[top] = dataStack[top] == 1 ? 0 : 1;
                        flag = dataStack[top] != 0;
                        top--;
                        pc++;
                        break;
                    case "bitxor":
                        dataStack[top] ^= dataStack[top - 1];
                        top--;
                        pc++;
                        break;
                    case "bitand":
                        dataStack[top] &= dataStack[top - 1];
                        top--;
                        pc++;
                        break;
                    case "bitor":
                        dataStack[top] |= dataStack[top - 1];
                        top--;
                        pc++;
                        break;
                    case "bitnot":
                        dataStack[top] = ~dataStack[top];
                        pc++;
                        break;
                    case "halt":
                        return;
                    case "inc":
                        dataStack[top]++;
                        pc++;
                        table.SetValue(tempId, dataStack[top], RunTimeType.Var);
                        top--;
                        break;
                    case "dec":
                        dataStack[top]--;
                        pc++;
                        table.SetValue(tempId, dataStack[top], RunTimeType.Var);
                        top--;
                        break;
                    default:
                        if (ins.OpCode[0] == 'L')
                            pc++;
                        else Console.WriteLine("Runtime Error at {0}", pc);
                        break;
                }
                if(switchs[0])
                    ShowStack();
            }
        }

        /// <summary>
        /// 显示堆栈
        /// </summary>
        private void ShowStack()
        {
            Console.Write("DataStack:\t");
            for (int i = top; i > -1; i--)
            {
                Console.Write("{0}|", dataStack[i]);
            }
            Console.WriteLine();
        }
    }
}
