using System.Linq;

namespace Intepreter
{
    enum RunTimeType
    {
        /// <summary>
        /// 变量
        /// </summary>
        Var,
        /// <summary>
        /// 数组（首地址）
        /// </summary>
        Array,
        /// <summary>
        /// 常量
        /// </summary>
        Const
    }

    /// <summary>
    /// 符号表表项
    /// </summary>
    struct TableItem
    {
        /// <summary>
        /// 名称
        /// </summary>
        public string Name;
        /// <summary>
        /// 值
        /// </summary>
        public int Value;

        /// <summary>
        /// 类型
        /// </summary>
        public RunTimeType Type;
    }

    /// <summary>
    /// 符号表
    /// </summary>
    class Table
    {
        private readonly TableItem[] table;
        private int pos;

        /// <summary>
        /// 构造方法
        /// </summary>
        public Table()
        {
            table = new TableItem[100];
            pos = 0;
        }

        /// <summary>
        /// 将符号表中的对应表项赋值
        /// </summary>
        /// <param name="name">符号名称</param>
        /// <param name="value">要赋给该符号的新值</param>
        /// <param name="t">符号的类型</param>
        public void SetValue(string name, int value, RunTimeType t)
        {
            int tmpPos = FindInTable(name);
            if (tmpPos == -1)
                EnterTable(new TableItem { Name = name, Value = value, Type = t });
            else table[tmpPos].Value = value;
        }

        /// <summary>
        /// 将未加入符号表的符号加入
        /// </summary>
        /// <param name="item">符号</param>
        public void EnterTable(TableItem item)
        {
            if (FindInTable(item.Name) == -1)
            {
                table[pos++] = item;
            }
        }

        /// <summary>
        /// 根据输入的符号名称，查找符号所在位置
        /// </summary>
        /// <param name="name">符号名称</param>
        /// <returns>符号所在的位置</returns>
        public int FindInTable(string name)
        {
            for (var tmpI = 0; tmpI < table.Count(); tmpI++)
            {
                if (table[tmpI].Name == name)
                {
                    return tmpI;
                }
            }
            return -1;
        }

        /// <summary>
        /// 根据符号名称，查找符号的值
        /// </summary>
        /// <param name="name">符号名称</param>
        /// <returns>该符号的值</returns>
        public int GetValue(string name)
        {
            var getedList = from item in table where item.Name == name select item;
            return getedList.Select(item => item.Value).FirstOrDefault();
        }
    }
}
