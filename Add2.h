#pragma once
#include "Add2.h"
#include <string.h>
#include <iostream>


#include <string>


using System::Runtime::InteropServices::Marshal;


namespace proekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;


	



	/// <summary>
	/// Сводка для Add2
	/// </summary>
	public ref class Add2 : public System::Windows::Forms::Form
	{
	public:
		Add2(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Add2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ Song1_name;
	private: System::Windows::Forms::TextBox^ Song1_text;



	private: System::Windows::Forms::TextBox^ Song1_author;
	private: System::Windows::Forms::Button^ Save1;



	protected:

	private:

		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Song1_name = (gcnew System::Windows::Forms::TextBox());
			this->Song1_text = (gcnew System::Windows::Forms::TextBox());
			this->Song1_author = (gcnew System::Windows::Forms::TextBox());
			this->Save1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::Info;
			this->label1->Location = System::Drawing::Point(58, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Заполните все поля";
			this->label1->Click += gcnew System::EventHandler(this, &Add2::label1_Click);
			// 
			// Song1_name
			// 
			this->Song1_name->BackColor = System::Drawing::SystemColors::Info;
			this->Song1_name->Location = System::Drawing::Point(12, 48);
			this->Song1_name->Name = L"Song1_name";
			this->Song1_name->Size = System::Drawing::Size(162, 20);
			this->Song1_name->TabIndex = 1;
			this->Song1_name->Text = L"имя";
			this->Song1_name->TextChanged += gcnew System::EventHandler(this, &Add2::textBox1_TextChanged);
			// 
			// Song1_text
			// 
			this->Song1_text->BackColor = System::Drawing::SystemColors::Info;
			this->Song1_text->Location = System::Drawing::Point(12, 74);
			this->Song1_text->Multiline = true;
			this->Song1_text->Name = L"Song1_text";
			this->Song1_text->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Song1_text->Size = System::Drawing::Size(334, 287);
			this->Song1_text->TabIndex = 2;
			this->Song1_text->Text = L"текст";
			// 
			// Song1_author
			// 
			this->Song1_author->BackColor = System::Drawing::SystemColors::Info;
			this->Song1_author->Location = System::Drawing::Point(181, 48);
			this->Song1_author->Name = L"Song1_author";
			this->Song1_author->Size = System::Drawing::Size(165, 20);
			this->Song1_author->TabIndex = 3;
			this->Song1_author->Text = L"автор";
			this->Song1_author->TextChanged += gcnew System::EventHandler(this, &Add2::Song1_author_TextChanged);
			// 
			// Save1
			// 
			this->Save1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->Save1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Save1->Location = System::Drawing::Point(12, 381);
			this->Save1->Name = L"Save1";
			this->Save1->Size = System::Drawing::Size(334, 51);
			this->Save1->TabIndex = 4;
			this->Save1->Text = L"Сохранить ";
			this->Save1->UseVisualStyleBackColor = false;
			this->Save1->Click += gcnew System::EventHandler(this, &Add2::Save1_Click);
			// 
			// Add2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(358, 444);
			this->Controls->Add(this->Save1);
			this->Controls->Add(this->Song1_author);
			this->Controls->Add(this->Song1_text);
			this->Controls->Add(this->Song1_name);
			this->Controls->Add(this->label1);
			this->Name = L"Add";
			this->Text = L"Add";
			this->ResumeLayout(false);
			this->PerformLayout();

			LoadSettings();
		}
#pragma endregion


	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Song1_author_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Save1_Click(System::Object^ sender, System::EventArgs^ e) {

		ofstream song2("song2.txt");
		song2 << toStandardString(Song1_name->Text) << endl << toStandardString(Song1_author->Text) << endl << toStandardString(Song1_text->Text);
		song2.close();


	}
	
	private: void LoadSettings() {
		string a1, a2, a3, a0;
		ifstream song2("song2.txt");
		getline(song2, a1);
		getline(song2, a2);
		while (!song2.eof()) {
			getline(song2, a0);
			a3 += a0;
			a3 += "\n";
		}

		Song1_name->Text = gcnew System::String(a1.c_str());
		Song1_author->Text = gcnew System::String(a2.c_str());
		Song1_text->Text = gcnew System::String(a3.c_str());
	}




		   static std::string toStandardString(System::String^ string)
		   {
			   System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
			   char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
			   std::string returnString(charPointer, string->Length);
			   Marshal::FreeHGlobal(pointer);

			   return returnString;
		   }
	};
}
