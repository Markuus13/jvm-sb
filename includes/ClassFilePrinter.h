/** @file ClassFilePrinter.h
 *  @brief Assinatura das funções/variáveis do módulo de saída de informações
 *  no terminal do L/E e JVM.
 */
#ifndef CLASS_FILE_PRINTER_H
#define CLASS_FILE_PRINTER_H

/** @cond */
#include <string>
/** @endcond */
#include "JavaClass.h"
#include "CpInfo.h"
#include "InterfaceInfo.h"
#include "AttributeInfo.h"


/**
 * @brief Classe de saída de informações no terminal do L/E e JVM.
 **/
class ClassFilePrinter {
public:
  // referência da constant pool
  CpInfo *cpinfo = new CpInfo();
  // referência das informações de interface
  InterfaceInfo *interface_info = new InterfaceInfo();
  // referência das informações de atributos
  AttributeInfo *attribute_info = new AttributeInfo();

  void print_menu_init();

  std::string print_menu_choose_type_file(std::string title);
  void print_general_info(JavaClass class_file, std::string filename);
  void print_menu_exhibitor(JavaClass class_file);
  void print_constant_pool_info(JavaClass class_file);
  void print_interfaces(JavaClass class_file);
  void print_fields_info(JavaClass class_file);
  void print_method(JavaClass class_file);
  void print_attributes_methods(JavaClass class_file);

  void print_attributes_methods(JavaClass class_file,
                                AttributeInfo attribute_info);
  void print_attr_code(JavaClass class_file, CodeAttribute info_code);
  void print_attr_number_table(JavaClass class_file,
                              LineNumberTableAttribute info_number_table);
  void print_attr_source_file(JavaClass class_file,
                              SourceFileAttribute info_code);
  void print_attr_constant_value(JavaClass class_file,
                                ConstantValueAttribute info_constant);
  void print_instructions(JavaClass class_file, CodeAttribute info_code);
};

#endif
