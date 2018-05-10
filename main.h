int registers[14];

std::mutex m;

void fetch();
void identify();
void execute();
void memory();
void writeback();

struct code{
	int opcode;	
	int destination;
	int source1;
	int source2;
	int imm;
	int writereg;
};

struct code im[1000];
