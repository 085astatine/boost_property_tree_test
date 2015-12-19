#ifndef IO_XML_H
#define IO_XML_H

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace io{
// load XML File
boost::property_tree::ptree load_xml(
            const std::string& xml_file);
// save XML File
void save_xml(
            const std::string& xml_file,
            const boost::property_tree::ptree& ptree);
}// end namespace io
#endif// IO_XML_H
