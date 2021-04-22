#pragma once

#include <string>
#include <vector>

enum ArgsStatus
{
    NoArgs = 0,
    FileAndKey,
    File,
    ErrorCount
};

class ArgsParser
{
public:

    ArgsParser( int argc, char* argv[] );

    ArgsStatus getStatus( );
    std::string getProgramPath( );
    std::string getFile( );
    std::string getKey( );
    std::pair< std::string, std::string > getFileAndKey( );


private:
    int m_argc;
    std::vector< std::string > m_argv;
    ArgsStatus m_status;
};
