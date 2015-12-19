#include <fstream>
#include <boost/property_tree/xml_parser.hpp>
#include "./xml.h"

namespace io{
// load XML File
boost::property_tree::ptree load_xml(
            const std::string& xml_file){
    std::ifstream fin(xml_file);
    boost::property_tree::ptree output_ptree;
    boost::property_tree::read_xml(
                fin,
                output_ptree,
                boost::property_tree::xml_parser::trim_whitespace);
    return output_ptree;
}
// save XML File
void save_xml(
            const std::string& xml_file,
            const boost::property_tree::ptree& ptree){
    std::ofstream fout(xml_file);
    boost::property_tree::xml_writer_settings<
                boost::property_tree::ptree::key_type>
    writer_setting(' ', 4);
    boost::property_tree::write_xml(
                fout,
                ptree,
                writer_setting);
}
}// end namespace io
