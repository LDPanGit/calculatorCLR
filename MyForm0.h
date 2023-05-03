#pragma once
//#include "MyDia1.h"
#include "Math0.h"
namespace btmTest {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    //using namespace diaTest;
    using namespace System::Threading;
    using namespace Mymath0;

    public ref class MyForm0 :public Form {
    public: MyForm0() {//呼叫
        //this->Width = 300; 
        //this->Height = 200;
        InCon();//
        //this->BackColor = Color::White;
    };
    private:
        Button^ button1;
        Button^ button2;
        Button^ button3;
        Button^ button4;
        Label^ label1;
        Label^ label2;
        Label^ label3;
        TextBox^ textbox1;
        TextBox^ textbox2;
        TextBox^ textbox3;
        ComboBox^ combobox1;
        void InCon() {
            this->Text = "計算機";
            double S = 2;//視窗倍率
            System::Drawing::Font^ MyFont0 = gcnew System::Drawing::Font("標楷體", 10 * S);
            //this->ClientSize = System::Drawing::Size(600, 400);
            int CSizeW = 430 * S;
            int CSizeH = 400 * S;
            this->ClientSize = System::Drawing::Size(CSizeW, CSizeH);
            button1 = gcnew Button;
            button1->Text = "幫助";
            button1->Size = System::Drawing::Size(80 * S, 25 * S);
            button1->Location = Point((CSizeW - button1->Width) * 0.5 / 4, (CSizeH - button1->Height) - 20 * S);
            button1->Click += gcnew EventHandler(this, &MyForm0::button1Click1);
            this->Controls->Add(button1);

            button2 = gcnew Button;
            button2->Text = "運算";
            button2->Size = System::Drawing::Size(80 * S, 25 * S);
            button2->Location = Point((CSizeW - button1->Width) * 2 / 4, (CSizeH - button1->Height) - 20 * S);
            button2->Click += gcnew EventHandler(this, &MyForm0::button2Click1);
            this->Controls->Add(button2);

            button3 = gcnew Button;
            button3->Text = "重置";
            button3->Size = System::Drawing::Size(80 * S, 25 * S);
            button3->Location = Point((CSizeW - button1->Width) * 3.5 / 4, (CSizeH - button1->Height) - 20 * S);
            button3->Click += gcnew EventHandler(this, &MyForm0::button3Click1);
            this->Controls->Add(button3);  

            textbox1 = gcnew TextBox;
            textbox1->Text = "輸入函式";
            textbox1->Font = MyFont0;
            //textbox1->TextAlign = HorizontalAlignment::Center;
            textbox1->Multiline = true;
            textbox1->Width = 200 * S;
            textbox1->Height = 30 * S;
            int textbox1X = CSizeW - 10 * S - textbox1->Width;
            int textbox1Y = 40 * S;
            textbox1->Location = Point(textbox1X, textbox1Y);
            this->Controls->Add(textbox1);

            textbox2 = gcnew TextBox;
            textbox2->Text = "結果";
            textbox2->Font = MyFont0;
            //textbox2->TextAlign = HorizontalAlignment::Center;
            textbox2->Multiline = true;
            textbox2->Width = 200 * S;
            textbox2->Height = 300 * S;
            int textbox2X = 10 * S;
            int textbox2Y = 40 * S;
            textbox2->Location = Point(textbox2X, textbox2Y);
            this->Controls->Add(textbox2);

            textbox3 = gcnew TextBox;
            textbox3->Text = "輸入參數";
            textbox3->Font = MyFont0;
            //textbox3->Visible = false;
            textbox3->Multiline = true;
            textbox3->Width = 200 * S;
            textbox3->Height = 30 * S;
            int textbox3X = textbox1X;
            int textbox3Y = textbox1Y * 2 + textbox1->Height;
            textbox3->Location = Point(textbox3X, textbox3Y);
            this->Controls->Add(textbox3);

            label1 = gcnew Label;
            label1->Text = "函式";
            label1->Font = MyFont0;
            //label1->TextAlign = ContentAlignment::MiddleCenter;
            label1->AutoSize = false;
            label1->Width = 200 * S;
            label1->Height = 60 * S;
            label1->Location = Point(textbox1X, textbox1Y - 20 * S);
            this->Controls->Add(label1);

            label2 = gcnew Label;
            label2->Text = "參數";
            label2->Font = MyFont0;
            label1->AutoSize = false;
            label1->Width = 200 * S;
            label1->Height = 60 * S;
            label2->Location = Point(textbox3X, textbox3Y - 20 * S);
            //label2->Visible = false;
            this->Controls->Add(label2);

            combobox1 = gcnew ComboBox;
            combobox1->Text = "功能";
            combobox1->Font = MyFont0;
            //textbox2->TextAlign = HorizontalAlignment::Center;
            combobox1->Width = 200 * S;
            combobox1->Height = 150 * S;
            int combobox1X = textbox1X;
            int combobox1Y = textbox3Y + textbox3->Height + textbox1Y;
            combobox1->Location = Point(combobox1X, combobox1Y);
            combobox1->Items->Add(gcnew String("四則運算"));
            combobox1->Items->Add(gcnew String("定積分"));
            combobox1->Items->Add(gcnew String("二重積分"));
            combobox1->Items->Add(gcnew String("微分"));
            combobox1->Items->Add(gcnew String("二次微分"));
            combobox1->Click += gcnew EventHandler(this, &MyForm0::combobox1Change);
            this->Controls->Add(combobox1);

            label3 = gcnew Label;
            label3->Text = "1.數字與符號間皆須加入空白鍵\n2.函數皆符合四則運算，可加入小括號、中括號與大括號，三角函數與對數後的內容皆須加入括號\n3.π請打pi 自然底數請打e\n";
            label3->Font = MyFont0;
            label3->AutoSize = false;
            label3->Width = 200 * S;
            label3->Height = 100 * S;
            label3->Location = Point(combobox1X, combobox1Y + combobox1->Height + 20 * S);
            //label3->Visible = false;
            this->Controls->Add(label3);

        };
        String^ Result;
        String^ inputFunction;
        String^ inputNum;
        String^ Var;
        array<String^>^ ArrNum;
        array<String^>^ ArrFunctionMath;
        array<String^>^ ArrFunctionCopy;
        #define LENDIF 1
        #define LENINTPI 2
        #define LENINTNUM 4
        //#define MaxF 3
        void button1Click1(Object^ senser, EventArgs^ e) {
            switch (combobox1->SelectedIndex) {
            case 0:
                textbox3->Text = "null";
                return;
            case 1:
                textbox3->Text = "LowX HighX";
                return;
            case 2:
                textbox3->Text = "LowX HighX LowY HighY";
                return;
            case 3:
                textbox3->Text = "x";
                return;
            case 4:
                textbox3->Text = "x";
                return;
            default:
                return;
            }
        };
        void button2Click1(Object^ senser, EventArgs^ e) {
            inputNum = textbox3->Text;
            inputFunction = textbox1->Text;
            ArrNum = inputNum->Split();//參數
            ArrFunctionMath = inputFunction->Split();//函數
            ArrFunctionCopy = inputFunction->Split();//複製用函數
            int len = ArrNum->Length;
            int len2 = ArrFunctionMath->Length;
            double sum, ANS;
            MyIntegral^ theInt0;
            MyIntegral^ theInt1;
            MyIntegral^ theInt2;
            MyIntegral^ theInt3;
            MyIntegral^ theInt4;
            switch (combobox1->SelectedIndex)
            {
            case 0:
                Result = Result + "四則運算: " + inputFunction + "\r\n";
                textbox2->Text = Result;
                /*double opd0[100];
                try {
                    for (int i = 0; i < len; i++) {
                        opd0[i] = Convert::ToDouble(ArrFunctionMath[i]);
                    }
                }
                catch (FormatException^ e) {
                    MessageBox::Show(e->Message);
                    return;
                }*/

                theInt0 = gcnew MyIntegral();
                theInt0->MyFormula(ArrFunctionMath);
                ANS = theInt0->ans;
                Result = Result + Convert::ToString(ANS) + "\r\n";
                textbox2->Text = Result;

                return;
            case 1:
                Result = Result + "定積分: " + inputFunction + "\r\n";
                Result = Result + "區間 [" + inputNum + "]" + "\r\n";
                textbox2->Text = Result;
                double opd1[LENINTPI];
                try {
                    for (int i = 0; i < len; i++) {
                        opd1[i] = Convert::ToDouble(ArrNum[i]);
                    }
                }
                catch (FormatException^ e) {
                    MessageBox::Show(e->Message);
                    return;
                }

                theInt1 = gcnew MyIntegral();//上屆下屆
                theInt1->MyIntegralx(opd1[LENINTPI - 2], opd1[LENINTPI - 1], ArrFunctionMath, ArrFunctionCopy);
                ANS = theInt1->ans;
                Result = Result + Convert::ToString(ANS) + "\r\n";
                textbox2->Text = Result;

                return;
            case 2:
                Result = Result + "二重積分: " + inputFunction + "\r\n";
                Result = Result + "區間 [" + inputNum + "]" + "\r\n";
                textbox2->Text = Result;
                double opd2[LENINTNUM];
                try {
                    for (int i = 0; i < len; i++) {
                        opd2[i] = Convert::ToDouble(ArrNum[i]);
                    }
                }
                catch (FormatException^ e) {
                    MessageBox::Show(e->Message);
                    return;
                }

                theInt2 = gcnew MyIntegral();
                theInt2->MyIntegralxy(opd2[LENINTNUM - 4], opd2[LENINTNUM - 3], opd2[LENINTNUM - 2], opd2[LENINTNUM - 1], ArrFunctionMath, ArrFunctionCopy);
                ANS = theInt2->ans;
                Result = Result + Convert::ToString(ANS) + "\r\n";
                textbox2->Text = Result;
                return;
            case 3:
                Result = Result + "微分: " + inputFunction + "\r\n";
                Result = Result + "x= " + inputNum + "\r\n";
                textbox2->Text = Result;
                double opd3[LENDIF];
                try {
                    for (int i = 0; i < len; i++) {
                        opd3[i] = Convert::ToDouble(ArrNum[i]);
                    }
                }
                catch (FormatException^ e) {
                    MessageBox::Show(e->Message);
                    return;

                }

                theInt3 = gcnew MyIntegral();
                theInt3->MyDif(opd3[0], ArrFunctionMath, ArrFunctionCopy);
                ANS = theInt3->ans;
                Result = Result + Convert::ToString(ANS) + "\r\n";
                textbox2->Text = Result;
                return;
            case 4:
                Result = Result + "二次微分: " + inputFunction + "\r\n";
                Result = Result + "x= " + inputNum + "\r\n";
                textbox2->Text = Result;
                double opd4[LENDIF];
                try {
                    for (int i = 0; i < len; i++) {
                        opd4[i] = Convert::ToDouble(ArrNum[i]);
                    }
                }
                catch (FormatException^ e) {
                    MessageBox::Show(e->Message);
                    return;

                }

                theInt4 = gcnew MyIntegral();
                theInt4->MyDif2(opd4[0], ArrFunctionMath, ArrFunctionCopy);
                ANS = theInt4->ans;
                Result = Result + Convert::ToString(ANS) + "\r\n";
                textbox2->Text = Result;
                return;
            default:
                break;
            }
        };
        void button3Click1(Object^ senser, EventArgs^ e) {
            textbox1->Text = "";
            textbox2->Text = "";
            textbox3->Text = "";
            Result = "";
        };

        void combobox1Change(Object^ senser, EventArgs^ e) {
            Var = Convert::ToString(combobox1->SelectedIndex);
            /*if (combobox1->SelectedIndex == 1 || combobox1->SelectedIndex == 2) {
                textbox3->Visible = true;
                label2->Visible = true;
            }*/
            //else textbox3->Visible = false;
            //textbox2->Text = Var;
            //textbox2->Text = "";
            //Result = "";
        };
    };
}
