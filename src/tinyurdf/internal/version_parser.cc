#include "internal/version_parser.h"

VersionParser::VersionParser(){
    p_ = std::make_shared<Version>();
};

void VersionParser::parse(tinyxml2::XMLDocument doc)
{
    tinyxml2::XMLDeclaration* decl = doc.FirstChild()->ToDeclaration();
    if (decl) 
    {
        const char* version_str = decl->Value();
        const char *versionStart = strstr(version_str, "version=\"");
        
        versionStart += 9; 
        char version_[20];  
        sscanf(versionStart, "%19[^\"]", version_); 

        const char* constVersion = version_;
        LOG_F(INFO, "XML Version detected: %s", constVersion);
        Version version(constVersion);
        p_ = std::make_shared<Version>(version);
        if (!version.equal(static_cast<double>(1), static_cast<double>(0)))
        {
            LOG_F(ERROR, "Parser Engine : only XML version 1.0 supported");
        }else {
            LOG_F(ERROR,"No XML declaration found!");
        }
    }
}

const char *VersionParser::getTypename() const
{
    return "version";
}
VersionParser::~VersionParser(){
    p_->~Version();
};