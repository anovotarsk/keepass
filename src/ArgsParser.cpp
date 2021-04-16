#include "ArgsParser.h"

ArgsParser::ArgsParser( int argc, char* argv[] )
    : m_argc( argc )
{
    for ( int i = 0; i < argc; i++ )
    {
        m_argv.push_back( { argv[ i ] } );
    }

    switch ( m_argc )
    {
        case 1:
            m_status = NoArgs;
            break;
        case 2:
            m_status = File;
            break;
        case 3:
            m_status = FileAndKey;
            break;
        default:
            m_status = ErrorCount;
    }
}

ArgsStatus ArgsParser::getStatus( )
{
    return m_status;
}

std::string ArgsParser::getFile( )
{
    return m_argv[ 1 ] ;
}

std::string ArgsParser::getKey( )
{
    return m_argv[ 2 ] ;
}

std::pair< std::string, std::string > ArgsParser::getFileAndKey( )
{
    return { m_argv[ 1 ] , m_argv[ 2 ] } ;
}
