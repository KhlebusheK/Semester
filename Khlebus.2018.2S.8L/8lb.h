#pragma once

#ifdef Product_EXPORTS
#define Product_API __declspec(dllexport) 
#else
#define Product_API __declspec(dllimport) 
#endif

namespace Product
{
	struct Product
	{
	public:
		Product_API Product() {};
		Product_API Product(char*, double, char*, char*, char*);
		Product_API ~Product();
		Product_API void SetName(char*);
		Product_API void SetCost(double*);
		Product_API void SetShelfLife(char*);
		Product_API void SetSort(char*);
		Product_API void SetReleaseDate(char*);
		Product_API void SetProduct(char*, double, char*, char*, char*);
		Product_API char* GetName();
		Product_API double GetCost();
		Product_API char* GetShelfLife();
		Product_API char* GetSort();
		Product_API char* GetReleaseDate();
		Product_API void EnterProduct();
		Product_API void DisplayProduct();

	private:
		char * name;
		double  cost;
		char * shelfLife;
		char * sort;
		char * releaseDate;

		char* AllocateMemory(char*);
	};
}