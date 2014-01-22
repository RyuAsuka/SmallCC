using System;

namespace Intepreter
{
    class Program
    {
        /// <summary>
        /// 解释器组件
        /// </summary>
        private static Intepreter intepreter;

        /// <summary>
        /// 应用程序的主入口点
        /// </summary>
        /// <param name="args">命令行参数列表</param>
        private static void Main(string[] args)
        {
            bool showStack = false;
            bool showCode = false;
            if (args[0] == "-help")
            {
                Console.WriteLine("Useage:");
                Console.WriteLine("smallint (FILENAME [-s] [-l]|-help)");
                Console.WriteLine("\t-s\tShow datastack");
                Console.WriteLine("\t-l\tList all codes during executing");
            }
            else
            {
                intepreter = new Intepreter(args[0]);
                if (args.Length == 2)
                {
                    if (args[1] == "-s") showStack = true;
                    else if (args[1] == "-l") showCode = true;
                    else
                    {
                        Console.WriteLine("Wrong Arguments. Please use \"-help\" to get more informations.");
                    }
                }
                else if (args.Length == 3)
                {
                    if ((args[1] == "-s" && args[2] == "-l") || (args[1] == "-l" && args[2] == "-s"))
                    {
                        showStack = true;
                        showCode = true;
                    }
                    else
                    {
                        Console.WriteLine("Wrong Arguments. Please use \"-help\" to get more informations.");
                    }
                }
                else if (args.Length > 3)
                {
                    Console.WriteLine("Too many arguments. Please use \"-help\" to get more informations.");
                }
                intepreter.GenerateCode();
                intepreter.ExecuteCode(new[] {showStack, showCode});
                Console.ReadLine();
            }
        }
    }
}
