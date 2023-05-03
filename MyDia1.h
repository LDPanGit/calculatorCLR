#pragma once
namespace diaTest {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    public ref class MyDia1 :public Form {
    public: MyDia1() {
        //this->Width = 300; 
        //this->Height = 200;
        InCon();
        //this->BackColor = Color::White;
    };
    private:
        Label^ label1;
        void InCon() {
            this->Text = "MyDia1";
            int CSizeW = 300;
            int CSizeH = 200;
            this->ClientSize = System::Drawing::Size(CSizeW, CSizeH);

            label1 = gcnew Label;
            this->Controls->Add(label1);
            static int cnt = 0;
            label1->Text = cnt.ToString();
            cnt++;
        };

    };
}