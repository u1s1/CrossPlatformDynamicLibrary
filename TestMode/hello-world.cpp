#include <cstdlib>
#include <iostream>
#include "../Out/Interface/CrossPlatformLoad.h"

int main() {
  hello();
  
  IMessage *face = Message("好大的太阳");
  face->ShowMsg();
  face->SetStr("再见，太阳系");
  face->ShowMsg();
  std::cout << face->GetStr() << std::endl;
  face->SetStr("我回来了，太阳系");
  face->ShowMsg();
  std::cout << face->GetStr() << std::endl;

  IExcel *excel = Excel();
  if(excel->CreateExcel("./create.xlsx"))
  {
    std::cout << "创建excel成功！" << std::endl;
  }
  else
  {
    std::cout << "创建excel失败！" << std::endl;
  }
  if(excel->SetCellStr(10, 10, "this is a test!"))
  {
    std::cout << "插入excel成功！" << std::endl;
  }
  else
  {
    std::cout << "插入excel成功！" << std::endl;
  }
  std::cout << "获取字符"<<excel->GetCellStr(10, 10) << std::endl;
  if(excel->Save("./save.xlsx"))
  {
    std::cout << "保存excel成功！" << std::endl;
  }
  else
  {
    std::cout << "保存excel失败！" << std::endl;
  }

  IExcel *newExcel = Excel();
  if(newExcel->OpenExcel("./testOpen.xlsx"))
  {
    std::cout << "打开excel成功！" << std::endl;
  }
  else
  {
    std::cout << "打开excel失败！" << std::endl;
  }

  if(newExcel->Save("./save1.xls"))
  {
    std::cout << "保存excel成功！" << std::endl;
  }
  else
  {
    std::cout << "保存excel失败！" << std::endl;
  }
  return 0;
}
