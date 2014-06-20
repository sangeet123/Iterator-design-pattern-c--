#ifndef DATA
#define DATA

	class Data{
		private:
			int i;
			int j;
			int refcount;
			Data(int ii=0, int jj=0):i(ii),j(jj),refcount(1){}
			Data(Data& d1);
			Data * operator = (Data& d2);

		public:

			/* Simple Factory pattern for creating Data type from the heap*/
			static Data* create(int ii=0, int jj=0){
				return new Data(ii,jj);
			}

			/* Overloading Output stream to display the Data information*/
			friend std::ostream& operator << (std::ostream& os, const Data& dat){
				os<<"i = "<<dat.i<<" ,"<<"j = "<<dat.j<<std::endl;
				return os;
			}

			/* Used for testing weather two data are equal or not*/
			bool operator == (Data &d2){
				return (i == d2.i && j == d2.j);
			}

			~Data(){}

};


#endif
