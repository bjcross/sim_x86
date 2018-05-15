
char im[1000][100];
int registers[14];

std::mutex m;

void fetch();
void identify();
void execute();
void memory();
void writeback();
