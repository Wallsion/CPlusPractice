#ifndef QUENUE_MINE
#define QUENUE_MINE
class quenue
{
public:
	quenue();
	~quenue();
	bool Qcreate(int q_length);
	bool Qdestory();
	bool Qin(int num);
	bool Qin(float num);
	int  Q_intout();
	float Q_floatout();
	int erroout(int ll);
private:
	int qlength;
	int *qzone;
	int *qhead;
	int *qtail;
	int qcurlength;
	int *cyclelabl;
};
#endif
