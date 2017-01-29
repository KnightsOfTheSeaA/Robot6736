#ifndef CannonFireCmd_H
#define CannonFireCmd_H

#include "../CommandBase.h"

class CannonFireCmd : public CommandBase {
public:
	CannonFireCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CannonFireCmd_H
