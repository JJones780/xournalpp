/*
 * Xournal++
 *
 * Autosave job
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "Job.h"

#include <XournalType.h>

class Control;

class AutosaveJob : public Job
{
public:
	AutosaveJob(Control* control);

protected:
	~AutosaveJob() override;

public:
	void run() override;
	void afterRun() override;

	JobType getType() override;

private:
	XOJ_TYPE_ATTRIB;


	Control* control = nullptr;
	string error;
};
