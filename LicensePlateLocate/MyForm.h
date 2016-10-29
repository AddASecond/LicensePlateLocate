#include <opencv\cv.h>
#include <opencv\highgui.h>
#include<string>
#pragma once

namespace LicensePlateLocate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	public:
		// add my vars here 2016
		int PicCount = 0;
		int TempPicNum = 0;
		int SelectedRow = 0;
		//array<int>^ LicensePlateLocation = gcnew array<int>(40); //to save license plate location
		//Array::Resize(LicensePlateLocation, LicensePlateLocation->Length+20);
		array<int,2>^ LicensePlateLocation = gcnew array<int,2>(10000,4); //to save license plate location
		array<int>^ tmpLPL = gcnew array<int>(4);

		//openCV variables
		IplImage* img0 = 0;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	public:

	public:
		CvMemStorage* storage = 0;

		//function
		void MarshalString(String ^ s, std::string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBox4;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;




	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->AutoSize = true;
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(742, 404);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"图片";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(3, 18);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(736, 383);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->groupBox2->Controls->Add(this->button6);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Location = System::Drawing::Point(759, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(216, 121);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"批量操作";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(32, 68);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(165, 34);
			this->button6->TabIndex = 5;
			this->button6->Text = L"导出车牌定位";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(122, 18);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"清空";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(32, 18);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"导入";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox3->AutoSize = true;
			this->groupBox3->Controls->Add(this->listView1);
			this->groupBox3->Location = System::Drawing::Point(12, 422);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(963, 353);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"帧";
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6
			});
			this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView1->Location = System::Drawing::Point(3, 18);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(957, 332);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"帧序号";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"图片名称";
			this->columnHeader2->Width = 180;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"图片类型";
			this->columnHeader3->Width = 120;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"图片大小";
			this->columnHeader4->Width = 180;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"车牌位置";
			this->columnHeader5->Width = 180;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"文件路径";
			this->columnHeader6->Width = 720;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"JPEG Files (*.jpg)|*.jpg|PNG Files (*.png)|*.png|BMP Files (*.bmp)|*.bmp|All file"
				L"s (*.*)|*.*";
			this->openFileDialog1->Multiselect = true;
			this->openFileDialog1->Title = L"选择一个图片文件";
			// 
			// groupBox4
			// 
			this->groupBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox4->AutoSize = true;
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Controls->Add(this->numericUpDown1);
			this->groupBox4->Controls->Add(this->button4);
			this->groupBox4->Controls->Add(this->button3);
			this->groupBox4->Location = System::Drawing::Point(760, 139);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(215, 277);
			this->groupBox4->TabIndex = 5;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"单张操作";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 126);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"上一帧/下一帧/跳帧";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(31, 149);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(165, 22);
			this->numericUpDown1->TabIndex = 5;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(31, 78);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(165, 33);
			this->button4->TabIndex = 3;
			this->button4->Text = L"车牌定位";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(31, 21);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(165, 34);
			this->button3->TabIndex = 2;
			this->button3->Text = L"删除";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"(text files(*.txt)|*.txt)";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(987, 787);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->MinimumSize = System::Drawing::Size(1005, 834);
			this->Name = L"MyForm";
			this->Text = L"License Plate Locate ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		TempPicNum = openFileDialog1->FileNames->Length;
		for (int i = 0; i < TempPicNum; i++) {
			pictureBox1->Load(openFileDialog1->FileNames[i]);
			PicCount += 1; //increase the count of pictures
			//add 1 picture to listview
			ListViewItem^ item1 = gcnew ListViewItem(PicCount.ToString(), 0);
			item1->SubItems->Add(Path::GetFileNameWithoutExtension(pictureBox1->ImageLocation));
			item1->SubItems->Add(Path::GetExtension(pictureBox1->ImageLocation)->Substring(1));
			item1->SubItems->Add(pictureBox1->Image->Size.ToString());
			item1->SubItems->Add("(0,0,0,0)");
			item1->SubItems->Add(pictureBox1->ImageLocation);
			listView1->Items->Add(item1);
		}
		pictureBox1->Load(openFileDialog1->FileNames[0]);
	}
}
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	Decimal index = numericUpDown1->Value;
	if (index <= 0 || index > PicCount || index != (int)numericUpDown1->Value) {
		MessageBox::Show("请输入序号范围内的整数数字！");
	}
	else {
		SelectedRow = (int)index-1;
		pictureBox1->Load(listView1->Items[SelectedRow]->SubItems[5]->Text);
		button4->PerformClick();// click button4 to locate the LP
	}
	//Graphics^ g1 = pictureBox1->CreateGraphics();
	//Pen^ skyBluePen1 = gcnew Pen(Brushes::DeepSkyBlue);	// Create a new pen.
	//skyBluePen1->Width = 2.0F;	// Set the pen's width.
	//skyBluePen1->LineJoin = System::Drawing::Drawing2D::LineJoin::Bevel;	// Set the LineJoin property.
	//g1->DrawRectangle(skyBluePen1, Rectangle(40, 40, 150, 150));
	//delete skyBluePen1;	//Dispose of the pen.
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	listView1->Items->RemoveAt(SelectedRow);
	PicCount -= 1;
	for (int i = SelectedRow; i < PicCount; i++) {
		listView1->Items[i]->SubItems[0]->Text= (i+1).ToString();
	}
	pictureBox1->Load(listView1->Items[SelectedRow]->SubItems[5]->Text);
	button4->PerformClick();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	listView1->Items->Clear();
	PicCount = 0;
	SelectedRow = 0;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	//detect the license plate location
	std::string tmp;
	MarshalString(listView1->Items[SelectedRow]->SubItems[5]->Text,tmp);
	storage = cvCreateMemStorage(0);
	img0 = cvLoadImage(tmp.c_str());

	//Image Processing
	//Step1: Convert to gray image
	IplImage* grayScale = cvCreateImage(cvGetSize(img0), img0->depth, 1);
	cvCvtColor(img0, grayScale, CV_BGR2GRAY);

	//Step2: Vertical image edge detection
	IplImage* sobel = cvCreateImage(cvGetSize(grayScale), IPL_DEPTH_16S, 1);
	cvSobel(grayScale, sobel, 2, 0, 7);
	IplImage* temp = cvCreateImage(cvGetSize(sobel), IPL_DEPTH_8U, 1);
	cvConvertScale(sobel, temp, 0.0039625, 0);

	//Step3: Adaptive binarization processing
	IplImage* threshold = cvCreateImage(cvGetSize(sobel), grayScale->depth, 1);
	cvThreshold(temp, threshold, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

	//Step4: Morphological manipulation
	IplConvKernel* kernal = cvCreateStructuringElementEx(3, 1, 1, 0, CV_SHAPE_RECT, NULL);
	IplImage* erode_dilate = cvCreateImage(cvGetSize(threshold), threshold->depth, 1);
	cvDilate(threshold, erode_dilate, kernal, 4);
	cvErode(erode_dilate, erode_dilate, kernal, 5);
	cvDilate(erode_dilate, erode_dilate, kernal, 3);

	kernal = cvCreateStructuringElementEx(1, 3, 0, 1, CV_SHAPE_RECT, NULL);
	cvErode(erode_dilate, erode_dilate, kernal, 1);
	cvDilate(erode_dilate, erode_dilate, kernal, 2);
	//cvShowImage(wndname, erode_dilate);

	//Step5: Contour detection
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contour;
	int count = cvFindContours(erode_dilate, storage, &contour, sizeof(CvContour), CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));
	CvSeq* _contour = contour;
	for (; contour != 0; contour = contour->h_next)
	{
		double tmparea = fabs(cvContourArea(contour, CV_WHOLE_SEQ, NULL));
		CvRect aRect = cvBoundingRect(contour, 1);
		if (tmparea > ((img0->height*img0->width) / 10))
		{
			cvSeqRemove(contour, 0); //
			continue;
		}
		if (aRect.width < (aRect.height * 2.5))
		{
			cvSeqRemove(contour, 0); //
			continue;
		}
		if ((aRect.width / aRect.height) > 4)
		{
			cvSeqRemove(contour, 0); //   
			continue;
		}
		if ((aRect.height * aRect.width) < ((img0->height * img0->width) / 100))
		{
			cvSeqRemove(contour, 0); //    
			continue;
		}
		CvScalar color = CV_RGB(255, 0, 0);
		//cvDrawRect(img0, cvPoint(aRect.x, aRect.y), cvPoint(aRect.x + aRect.width, aRect.y + aRect.height), color, 1, 8, 0);
		tmpLPL[0] = aRect.x; tmpLPL[1] = aRect.y; tmpLPL[2] = aRect.x + aRect.width; tmpLPL[3] = aRect.y + aRect.height;
		//cvDrawContours(img0, aRect, color, color, 0, 1, 8, cvPoint(0, 0));//»æÖÆÍâ²¿ºÍÄÚ²¿µÄÂÖÀª  
	}

	//save the license plate location
	LicensePlateLocation->SetValue(tmpLPL[0], SelectedRow,0);
	LicensePlateLocation->SetValue(tmpLPL[1], SelectedRow, 1);
	LicensePlateLocation->SetValue(tmpLPL[2], SelectedRow, 2);
	LicensePlateLocation->SetValue(tmpLPL[3], SelectedRow, 3);
	listView1->Items[SelectedRow]->SubItems[4]->Text = "("+ tmpLPL[0].ToString()+","+ tmpLPL[1].ToString() + "," + tmpLPL[2].ToString() + "," + tmpLPL[3].ToString() + ")";
	//draw the rectangle of license plate location
	double wfactor = (double)img0->width / pictureBox1->ClientSize.Width;
	double hfactor = (double)img0->height / pictureBox1->ClientSize.Height;
	double resizeFactor = 1/Math::Max(wfactor, hfactor);
	//double imageSize = new Size((int)(img.Width / resizeFactor), (int)(img.Height / resizeFactor));
	tmpLPL[0] *= resizeFactor;
	tmpLPL[1] *= resizeFactor;
	tmpLPL[2] *= resizeFactor;
	tmpLPL[3] *= resizeFactor;
	if (Math::Max(wfactor, hfactor) == hfactor) {
		tmpLPL[0] += (double)(pictureBox1->ClientSize.Width - img0->width*resizeFactor) / 2;
		tmpLPL[2] += (double)(pictureBox1->ClientSize.Width - img0->width*resizeFactor) / 2;
	}
	else if (Math::Max(wfactor, hfactor) == wfactor) {
		tmpLPL[1] += (double)(pictureBox1->ClientSize.Height - img0->height*resizeFactor) / 2;
		tmpLPL[3] += (double)(pictureBox1->ClientSize.Height - img0->height*resizeFactor) / 2;
	}
	Graphics^ g = pictureBox1->CreateGraphics();
	Pen^ skyBluePen = gcnew Pen(Brushes::DeepSkyBlue);	// Create a new pen.
	skyBluePen->Width = 2.0F;	// Set the pen's width.
	skyBluePen->LineJoin = System::Drawing::Drawing2D::LineJoin::Bevel;	// Set the LineJoin property.
	g->DrawRectangle(skyBluePen, Rectangle(tmpLPL[0], tmpLPL[1], tmpLPL[2]- tmpLPL[0], tmpLPL[3]-tmpLPL[1]));
	delete skyBluePen;	//Dispose of the pen.
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//显示文件的全路径
		StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);
		for (int i = 0; i < PicCount; i++) {
			sw->WriteLine(listView1->Items[i]->SubItems[4]->Text);
		}
		sw->Close();
	}
}
};
}
