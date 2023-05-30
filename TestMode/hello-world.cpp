#include <cstdlib>
#include <iostream>
#include "../Library/Interface/CrossPlatformLoad.h"

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
  if(excel->Save("./save.xlsx"))
  {
    std::cout << "保存excel成功！" << std::endl;
  }
  else
  {
    std::cout << "保存excel失败！" << std::endl;
  }

  if(excel->OpenExcel("./testOpen.xlsx"))
  {
    std::cout << "打开excel成功！" << std::endl;
  }
  else
  {
    std::cout << "打开excel失败！" << std::endl;
  }

  if(excel->Save("./save1.xls"))
  {
    std::cout << "保存excel成功！" << std::endl;
  }
  else
  {
    std::cout << "保存excel失败！" << std::endl;
  }
  return 0;
}
