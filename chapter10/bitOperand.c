struct SINGLE_OPERAND {
	unsigned int dst_reg : 3;
	unsigned int dst_mode : 3;
	unsigned int opcode : 10;
};

struct DOUBLE_OPERAND {
	unsigned int dst_reg : 3;
	unsigned int dst_mode : 3;
	unsigned int src_reg : 3;
	unsigned int src_mode : 3;
	unsigned int opcode : 4;
};

struct BRANCH {
	unsigned int offset : 8;
	unsigned int opcode : 8;
};

struct REGISTER_SOURCE {
	unsigned int dst_reg : 3;
	unsigned int dst_mode : 3;
	unsigned int src_reg : 3;
	unsigned int opcode : 7;
};

struct MISCELLANEOUS {
	unsigned int opcode : 16;
};

typedef struct INSTRUCTION {
	unsigned short addr : 16;
	union {
		struct SINGLE_OPERAND sgl_op;
		struct DOUBLE_OPERAND dbl_op;
		struct BRANCH branch;
		struct REGISTER_SOURCE reg_src;
		struct MISCELLANEOUS misc;
	} inst;
} machine_inst;
