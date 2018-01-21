#include "Company.h"

class Directory
{

private:
	Company * company;
	string file;
	int colCom;

public:

	Directory();
	void SavePlane(int i);
	void SetFileCom();
	void GetFilePlanes(int i);
	int FileCol();
	void GetFileComp();
	void PrintNames();
	void AddPlane(int i);
	void DelPlane(int i);
	~Directory();
};