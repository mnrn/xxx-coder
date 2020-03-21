using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using static System.Console;
using static System.Math;

namespace AtCoder
{
    public class Program 
    {
        public static void Main (string[] args)
        {
            var rx = new Regex(@"\A(dream(er)?|eraser?)+\z", RegexOptions.ExplicitCapture);
            var S = Console.ReadLine();
            Console.WriteLine(rx.IsMatch(S) ? "YES" : "NO");
        }
    }
}
