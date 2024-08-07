using System;
using System.Runtime.CompilerServices;
// See https://aka.ms/new-console-template for more information
namespace MyNamespace
{
    public static class StaticClass { }
    enum EnumHere { ValueOne, ValueTwo, }
    interface IThisIsAnInterface { }
    /// <summary>
    /// Bank account demo class.
    /// </summary>
    public class MyClass : IThisIsAnInterface
    {
        private double classField;
        private MyClass() { }

        public MyClass(string customerName, double balance)
        {
            classField = balance;
            var st8 = "raw string literal";
            var str = @"raw string literal";


            Console.WriteLine(str); //Single line comment
            List<IThisIsAnInterface> foo = new List<MyClass> { new MyClass() }
                                        .Where(g => g.Property == 10)
                                        .Select(g => (IThisIsAnInterface)g)
                                        .ToList();
        }
        public double Property { get { return classField; } }
        public int Credit(double amount)
        {
            var ten = 10;
            if (amount < 0)
            {
                throw new ArgumentOutOfRangeException("amount");
            }
            for (int i = 0; i <= 10; i++)
            {
                var foo = "\n test";

            }
            classField += ten;

            return 0;
        }
    }
}

