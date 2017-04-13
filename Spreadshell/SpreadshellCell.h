#pragma once
#include <string>
class SpreadshellCell
{
public:
    SpreadshellCell();
    virtual ~SpreadshellCell();
    virtual void set(const std::string) = 0;
    virtual std::string getString() const = 0;
};

