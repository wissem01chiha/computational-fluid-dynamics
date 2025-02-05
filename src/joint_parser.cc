#include "joint_parser.h"

JointParser::JointParser()
{
    p_ = std::make_shared<Joint>();
}

void JointParser::parse(const tinyxml2::XMLElement *xml)
{
    ParserBase<Joint>::parse(xml);
    const char* name_ = ParserBase<Joint>::getNameOf(xml);
    p_->setName(std::string(name_));
    const tinyxml2::XMLElement *axis_xml = xml->FirstChildElement("axis");
    if(axis_xml){
        const char* axis_str = axis_xml->Attribute("xyz");
        if(axis_str){
            double v[3];
            str2array(axis_str,v);
            p_->setAxis(v[0],v[1],v[2]);
        }
    }
    const char* type_str = xml->Attribute("type");
    if(type_str){
        p_->setType(type_str);
    }
    const tinyxml2::XMLElement *parent_xml = xml->FirstChildElement("parent");
    while (parent_xml)
    {
        const char* parent_str = parent_xml->Attribute("link");

        if(parent_str){
            if(!p_->isParent(parent_str)){
                p_->pushBackParent(std::string(parent_str));
            }
        }
        parent_xml = parent_xml->NextSiblingElement("parent");
    }
    
    const tinyxml2::XMLElement *child_xml = xml->FirstChildElement("child");
    while (child_xml)
    {
        const char* child_str = child_xml->Attribute("link");
        if(child_str){
            if(!p_->isChild(child_str)){
                p_->pushBackChild(std::string(child_str));
            }
        }
        child_xml = child_xml->NextSiblingElement("child");
    }

    const tinyxml2::XMLElement * origin_xml = xml->FirstChildElement("origin");
    while(origin_xml)
    {
        PoseParser op;
        op.parse(origin_xml);
        const auto o = op.get();
        p_->pushBackTransform(o);

        const char* ref_str = origin_xml->Attribute("parent");
         if(!ref_str){
            break;
        }else{
            if(!p_->isParent(ref_str))
            {
                LOG_F(ERROR,
                "specified parent '%s' in origin of joint '%s' does not match any known parent links.",
                ref_str, p_->getName().c_str());
                break;
            }
        }
        origin_xml = origin_xml->NextSiblingElement("origin");
    }


    const tinyxml2::XMLElement * calibration_xml = xml->FirstChildElement("calibration");
    if(calibration_xml){
        PropertyParser<double> calibration_parser;
        calibration_parser.parse(calibration_xml);
        const auto data = calibration_parser.get();
        std::shared_ptr<JointCalibration> jc = std::make_shared<JointCalibration>();
        jc->setFalling((*data)["falling"]);
        jc->setRising((*data)["rising"]);
        jc->setReferencePosition((*data)["reference_position"]);
        p_->setCalibration(jc);
    }
    
    const tinyxml2::XMLElement * limit_xml = xml->FirstChildElement("limit");
    if(limit_xml){
        PropertyParser<double> limit_parser;
        limit_parser.parse(limit_xml);
        const auto data = limit_parser.get();
        std::shared_ptr<JointLimits> jl = std::make_shared<JointLimits>();
        jl->setEffort((*data)["effort"]);
        jl->setVelocity((*data)["velocity"]);
        p_->setLimits(jl);
    }

    const tinyxml2::XMLElement * dynamics_xml = xml->FirstChildElement("dynamics");
    if(dynamics_xml){
        PropertyParser<double> dynamics_parser;
        dynamics_parser.parse(dynamics_xml);
        const auto data = dynamics_parser.get();
        std::shared_ptr<JointDynamics> jd = std::make_shared<JointDynamics>();
        jd->setDamping((*data)["damping"]);
        jd->setFriction((*data)["friction"]);
        jd->setInertia((*data)["inertia"]);
        p_->setDynamics(jd);
    }
    const tinyxml2::XMLElement * mimic_xml = xml->FirstChildElement("mimic");
    if(mimic_xml){
        PropertyParser<double> mimic_parser;
        mimic_parser.parse(mimic_xml);
        const auto data = mimic_parser.get();
        std::shared_ptr<JointMimic> jm = std::make_shared<JointMimic>();
        jm->setMultiplier((*data)["multiplier"]);
        jm->setOffset((*data)["offset"]);

        PropertyParser<std::string> str_mimic_parser;
        str_mimic_parser.parse(mimic_xml);
        const auto data_str = str_mimic_parser.get();
        jm->setName((*data_str)["joint"]);
        p_->setMimic(jm);
    }
    
    const tinyxml2::XMLElement * safety_xml = xml->FirstChildElement("safety_controller");
    if(safety_xml){
        PropertyParser<double> safety_parser;
        safety_parser.parse(safety_xml);
        const auto data = safety_parser.get();
        std::shared_ptr<JointSafety> js = std::make_shared<JointSafety>();
        js->setSoftUpperLimit((*data)["soft_upper_limit"]);
        js->setSoftLowerLimit((*data)["soft_lower_limit"]);
        js->setKPosition((*data)["k_position"]);
        js->setKVelocity((*data)["k_velocity"]);
        p_->setSafety(js);
    }
}

const char *JointParser::getTypename()
{
    return p_->getTypename();
}

std::shared_ptr<Joint> JointParser::get()
{
    return p_;
}

void JointParser::clear()
{
    p_->clear();
}

bool JointParser::empty() const
{
    return p_->empty();
}

void JointParser::print(std::ostream &os) 
{
    os << "Parsed Joint = [";
    p_->print(os);
    os << "]";
}

bool JointParser::isA(const char *name)
{
    return p_->isA(name);
}
JointParser::~JointParser() {
};
