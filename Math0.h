#pragma once
#include <cmath>
#include <math.h>
#define pi 3.14159265358979
#define E 2.718281828459045

namespace Mymath0 {
    using namespace System;
    using namespace std;
    
    public ref class MyIntegral {
    public:
        long n = 10000;//黎曼和
        double ans = 0;
        void MyIntegralx(double LowPi, double HighPi, array<String^>^ s1, array<String^>^ s2) {
            ans =  integralx(LowPi, HighPi, n, s1 , s2);
        };

        void MyIntegralxy(double LowNum1, double HighNum1,double LowNum2,double HighNum2, array<String^>^ s1, array<String^>^ s2) {
            ans = integralxy(LowNum1, HighNum1, LowNum2, HighNum2, n, s1, s2);
        };
        void MyFormula(array<String^>^ s) {
            ans = fR(s);
        }
        void MyDif(double X, array<String^>^ s1, array<String^>^ s2) {
            ans = dif(X, s1, s2);
        }
        void MyDif2(double X, array<String^>^ s1, array<String^>^ s2) {
            ans = dif2(X, s1, s2);
        }
    private:
        array<String^>^ c; //
        double fR(array<String^>^ s) {
            c = s;
            for (int j = 0; j < c->Length; j++) {
                if (c[j] == "e")c[j] = Convert::ToString(E);//這裡跟樓下的判別差在哪
                if (c[j] == "pi")c[j] = Convert::ToString(pi);
            }
            return arithmeticN(c);
        }
        double fxy(double x, double y, array<String^>^ s1, array<String^>^ s2)
        {
            c = s1;
            for (int k = 0; k < c->Length; k++)
            {
                c[k] = s2[k];//還原
            }

            for (int j = 0; j < c->Length; j++) {
                if (c[j] == "x")c[j] = Convert::ToString(x);
                if (c[j] == "y")c[j] = Convert::ToString(y);
                if (c[j] == "e")c[j] = Convert::ToString(E);
                if (c[j] == "pi")c[j] = Convert::ToString(pi);
            }
            return arithmeticN(c);
        }
        double integralxy(double xL, double xH, double yL, double yH, long n, array<String^>^ s1, array<String^>^ s2)//
        {
            double x, y, dx, dy, sum;
            dx = (xH - xL) / n;
            dy = (yH - yL) / n;
            x = xL + 0.5 * dx;
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                y = yL + 0.5 * dy;
                for (int j = 0; j < n; j++)
                {
                    sum += dx * dy * fxy(x, y, s1, s2);
                    y += dy;
                }
                x += dx;
            }
            return sum;
        }       
        double fx(double x, array<String^>^ s1, array<String^>^ s2) {
            c = s1;
            for (int k = 0; k < c->Length; k++)
            {
                c[k] = s2[k]; 
            }

            for (int j = 0; j < c->Length; j++) {               
                if (c[j] == "x")c[j] = Convert::ToString(x);
                if (c[j] == "e")c[j] = Convert::ToString(E);
                if (c[j] == "pi")c[j] = Convert::ToString(pi);
            }
            return arithmeticN(c);
        }
        double integralx(double L, double H, long n, array<String^> ^ s1, array<String^>^ s2)//
        {
            double x, dx, sum;
            dx = (H - L) / n;
            x = L + 0.5 * dx;
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += fx(x, s1, s2) * dx;//重複帶進去計算
                x += dx;
            }
            return sum;
        }
        double dif(double X, array<String^>^ s1, array<String^>^ s2) {//
            double x1, x2, y1, y2, dx,m1;
            dx = 0.000001;
            x1 = X;
            x2 = x1 + dx;
            y1 = fx(x1, s1, s2);
            y2 = fx(x2, s1, s2);
            m1 = (y2 - y1) / (x2 - x1);
            return m1;
        }
        double dif2(double X, array<String^>^ s1, array<String^>^ s2) {//
            double x1, x2, y1, y2, dx , m1,x3,y3,m2;
            dx = 0.000001;
            x1 = X;
            x2 = x1 + dx;
            x3 = x2 + dx;
            y1 = fx(x1, s1, s2);
            y2 = fx(x2, s1, s2);
            y3 = fx(x3, s1, s2);
            m1 = (y2 - y1) / (x2 - x1);
            m2 = (y3 - y2) / (x3 - x2);
            return (m2-m1)/dx;
        }
        void arithmetic(array<String^>^ c,int L,int R) {
            int cntL = 0;
            int cntH = 0;
            for (int i = L; i < R; i++) {
                if (c[i] == "^") {
                    cntL = 1;
                    while (c[i - cntL] == "null")
                    {
                        cntL++;
                    }
                    cntH = 1;
                    while (c[i + cntH] == "null")
                    {
                        cntH++;
                    }
                    c[i] = Convert::ToString(pow(Convert::ToDouble(c[i - cntL]), Convert::ToDouble(c[i + cntH])));
                    c[i - cntL] = "null"; c[i + cntH] = "null";
                }
            }
            for (int i = L; i < R; i++) {
                if (c[i] == "*") {
                    cntL = 1;
                    while (c[i - cntL] == "null")
                    {
                        cntL++;
                    }
                    cntH = 1;
                    while (c[i + cntH] == "null")
                    {
                        cntH++;
                    }
                    c[i] = Convert::ToString(Convert::ToDouble(c[i - cntL]) * Convert::ToDouble(c[i + cntH]));
                    c[i - cntL] = "null"; c[i + cntH] = "null";
                }
                if (c[i] == "/") {
                    cntL = 1;
                    while (c[i - cntL] == "null")
                    {
                        cntL++;
                    }
                    cntH = 1;
                    while (c[i + cntH] == "null")
                    {
                        cntH++;
                    }
                    c[i] = Convert::ToString(Convert::ToDouble(c[i - cntL]) / Convert::ToDouble(c[i + cntH]));
                    c[i - cntL] = "null"; c[i + cntH] = "null";
                }
            }
            for (int i = L; i < R; i++) {
                if (c[i] == "+") {
                    cntL = 1;
                    while (c[i - cntL] == "null")
                    {
                        cntL++;
                    }
                    cntH = 1;
                    while (c[i + cntH] == "null")
                    {
                        cntH++;
                    }
                    c[i] = Convert::ToString(Convert::ToDouble(c[i - cntL]) + Convert::ToDouble(c[i + cntH]));
                    c[i - cntL] = "null"; c[i + cntH] = "null";
                }
                if (c[i] == "-") {
                    cntL = 1;
                    while (c[i - cntL] == "null")
                    {
                        cntL++;
                    }
                    cntH = 1;
                    while (c[i + cntH] == "null")
                    {
                        cntH++;
                    }
                    c[i] = Convert::ToString(Convert::ToDouble(c[i - cntL]) - Convert::ToDouble(c[i + cntH]));
                    c[i - cntL] = "null"; c[i + cntH] = "null";
                }
            }
        }
        double arithmeticN(array<String^>^ c) {//

            int L = 0;
            int R = 0;
            for (int i = 0; i < c->Length; i++)
            {
                if (c[i] == "(") {//
                    L = i+1;
                    for (int j = i + 1; j < c->Length; j++) {
                        if (c[j] == ")") {
                            R = j;
                            arithmetic(c,L,R);
                            c[i] = "null";
                            c[j] = "null";
                            break;
                        }
                    }
                }
            }
            for (int iW = 0; iW < c->Length; iW++)
            {
                if (c[iW] == "sin") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {//跳出去
                        if (c[jW] == "[" || c[jW] == "{")
                            break;
                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(sin(Convert::ToDouble(c[jW])));//字串帶入計算轉成的結果是字串
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "cos") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {
                        if (c[jW] == "[" || c[jW] == "{")
                            break;
                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(cos(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "tan") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {
                        if (c[jW] == "[" || c[jW] == "{")
                            break;
                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(tan(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "log") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {
                        if (c[jW] == "[" || c[jW] == "{")
                            break;
                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(log10(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "ln") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {
                        if (c[jW] == "[" || c[jW] == "{")
                            break;
                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(log(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
            }
            for (int i2 = 0; i2 < c->Length; i2++)
            {
                if (c[i2] == "[") {
                    L = i2 + 1;
                    for (int j2 = i2 + 1; j2 < c->Length; j2++) {
                        if (c[j2] == "]") {
                            R = j2;
                            arithmetic(c, L, R);
                            c[i2] = "null";
                            c[j2] = "null";
                            break;
                        }
                    }
                }
            }
            for (int iW = 0; iW < c->Length; iW++)
            {
                if (c[iW] == "sin") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {
                        if ( c[jW] == "{")
                            break;
                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(sin(Convert::ToDouble(c[jW])));//字串帶入計算轉成的結果是字串
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "cos") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {
                        if ( c[jW] == "{")
                            break;
                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(cos(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "tan") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {
                        if ( c[jW] == "{")
                            break;
                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(tan(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "log") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {
                        if (c[jW] == "{")
                            break;
                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(log10(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "ln") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {
                        if ( c[jW] == "{")
                            break;
                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(log(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
            }
            for (int i3 = 0; i3 < c->Length; i3++)
            {
                if (c[i3] == "{") {
                    L = i3 + 1;
                    for (int j3 = i3 + 1; j3 < c->Length; j3++) {
                        if (c[j3] == "}") {
                            R = j3;
                            arithmetic(c, L, R);
                            c[i3] = "null";
                            c[j3] = "null";
                            break;
                        }
                    }
                }
            }
            for (int iW = 0; iW < c->Length; iW++)
            {
                if (c[iW] == "sin") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {

                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(sin(Convert::ToDouble(c[jW])));//字串帶入計算轉成的結果是字串
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "cos") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {

                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(cos(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "tan") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {

                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(tan(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "log") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {

                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(log10(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
                if (c[iW] == "ln") {
                    for (int jW = iW + 1; jW < c->Length; jW++) {
                    
                        if (c[jW] != "null") {
                            c[iW] = Convert::ToString(log(Convert::ToDouble(c[jW])));
                            //arithmetic(c, L, R);
                            c[jW] = "null";
                            break;
                        }
                    }
                }
            }
            arithmetic(c, 0, c->Length);//括號外的四則運算 (2*)cos2x
            int cntE = 0;
            while (c[cntE] == "null") {//找不是空的職
                cntE++;
            }
            double^ ansI = Convert::ToDouble(c[cntE]);//回傳直
            return *ansI;
        }
    };
}