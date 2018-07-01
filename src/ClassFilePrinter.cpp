/** @file ClassFilePrinter.c
 *  @brief Funções de impressão da interface do sistema e exibidor
 *    do arquivo ".class".
 *  @bug No know bugs.
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "ClassFilePrinter.h"
#include "JavaClass.h"
#include "ReadBytes.h"

/** @brief Mostra menu inicial para escolher tipo de arquivo java de teste.
*  @return void
*/
std::string ClassFilePrinter::print_menu_choose_type_file() {
  int option = 0;
  std::string filename;

  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\n\nLeitor/Exibidor: \n");
  printf("---------------------\n");

  printf("Insira qual tipo de arquivo java gostaria de testar:\n");
  printf("1. String\n");
  printf("2. Simulação de impressão\n");
  printf("3. Vetor unidimensional\n");
  printf("4. Vetor multidimensional\n");
  printf("5. Herança\n");
  printf("6. Reescrita\n");
  printf("7. Float\n");
  printf("8. Interface\n");
  printf("9. Inteiro\n");
  printf("10. Polimorfismo\n");
  printf("11. Double\n");
  printf("12. Static\n");
  printf("13. Atributo de instancia\n");
  printf("14. Atributo de classe\n");
  printf("15. Metodos Dinamicos\n");
  printf("16. Attributos\n");
  printf("0. Sair\n");
  scanf("%d", &option);

  switch (option) {
    case 1:
      filename = "test/StringDemo.class";
      break;
    case 2:
      filename = "test/PrintDemo.class";
      break;
    case 3:
      filename = "test/ArrayUniDemo.class";
      break;
    case 4:
      filename = "test/ArrayMultDemo.class";
      break;
    case 5:
      filename = "test/SuperClassInheritanceDemo.class";
      break;
    case 6:
      filename = "test/RewriteDemo.class";
      break;
    case 7:
      filename = "test/FloatDemo.class";
      break;
    case 8:
      filename = "test/InterfaceDemo.class";
      break;
    case 9:
      filename = "test/IntegerDemo.class";
      break;
    case 10:
      filename = "test/PolDemo.class";
      break;
    case 11:
      filename = "test/DoubleDemo.class";
      break;
    case 12:
      filename = "test/MethodStaticDemo.class";
      break;
    case 13:
      filename = "test/AttributeInstDemo.class";
      break;
    case 14:
      filename = "test/AttributeClassDemo.class";
      break;
    case 15:
      filename = "test/MethodDynamicDemo.class";
      break;
    case 16:
      filename = "test/AttributesDemo.class";
      break;
    case 0:
      printf("Até mais!\n");
      exit(0);
    default:
      printf("Opção não existe, tente novamente. Pressione enter...\n");
      char command;
      scanf("%c", &command);
      while ((command = getchar()) != '\n' && command != EOF) { };
      print_menu_choose_type_file();
  }

  return filename;
}

/** @brief Mostra informações básicas do Class File.
*  @return void
*/
void ClassFilePrinter::print_general_info(JavaClass class_file,
                                          std::string filename) {
  std::cout << "Filename:             " << filename << std::endl;
  printf("Magic Number:         0x%0X\n", class_file.magic_number);
  printf("Minor Version:        %d\n", class_file.minor_version);
  printf("Major version:        %d\n", class_file.major_version);
  printf("Contanst pool count:  %d\n", class_file.constant_pool_count);
  printf("Access flags:         0x%.4x\n", class_file.access_flags);
  printf("This class:           cp_info #%d < ", class_file.this_class);
  std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
  class_file.constant_pool[(class_file.this_class)-1].Class.type_class_info-1)
  << " >";
  printf("\nSuper class:          cp_info #%d < ", class_file.super_class);
  std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
  class_file.constant_pool[(class_file.super_class)-1].Class.type_class_info-1)
  << " >";
  printf("\nInterface count: %d\n", class_file.interfaces_count);
  printf("Field count: %d\n", class_file.fields_count);
  printf("Methods count: %d\n", class_file.methods_count);
  printf("Attributes count: %d\n", class_file.attributes_count);
}

/** @brief Mostra menu de escolhas do exibidor do arquivo .class.
 *  @param class_file ponteiro com as informações lidas do .class
 *  @return void
 */
void ClassFilePrinter::print_menu_exhibitor(JavaClass class_file) {
  int option = 0;

  printf("\n\nQue estrutura de dados deseja imprimir do arquivo .class:\n");
  printf("1. Constant Pool\n");
  printf("2. Interface\n");
  printf("3. Fields\n");
  printf("4. Methods\n");
  printf("5. Attributes\n");
  printf("0. Sair\n");
  scanf("%d", &option);

  switch (option) {
    case 1:
      // exibe informações das constant_pools
      print_constant_pool_info(class_file);
      break;
    case 2:
      // exibe as interfaces implementadas pela classe
      // print_interfaces(class_file);
      break;
    case 3:
      // print_fields_info(class_file);
      break;
    case 4:
      printf("Não implementado");
      break;
    case 5:
      printf("Não implementado");
      break;
    case 0:
      printf("Até mais!\n");
      exit(0);
    default:
      printf("Opção não existe, tente novamente. Pressione enter...\n");
      char command;
      scanf("%c", &command);
      while ((command = getchar()) != '\n' && command != EOF) { };
      print_menu_exhibitor(class_file);
  }
}

/** @brief Printa as interfaces contidas no .class
 *  @param class_file
 *  @return void
 */
void ClassFilePrinter::print_interfaces(JavaClass class_file){
  printf("\n--------------- Interfaces Info ---------------\n");

  // interface_info = class_file.interfaces;

  for (int i = 0; i < class_file.interfaces_count-1; i++)
  {
    // printf("Interface: cp info #%d <", class_file.interfaces[i].interface_table);
    // std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                                    // class_file->interfaces.interface_count[i]-1);
    printf("\n");
  }
}



/** @brief Mostra informações das constant_pools.
 *  Tabela de estruturas representando string, nomes de classes ou interfaces,
 *  nomes de campos, etc.
 *  @param class_file ponteiro com as informações lidas do .class
 *  @return void
 */
void ClassFilePrinter::print_constant_pool_info(JavaClass class_file) {
  std::cout << std::endl << std::endl << "------- Constant Pool -------" << std::endl << std::endl;

  for (int i = 0; i < class_file.constant_pool_count-1; i++) {

    std::cout << std::endl << "CP_INFO["<< i+1 << "]" << std::endl;

    // formato de cada entrada é indicado pelo byte tag
    switch (class_file.constant_pool[i].tag) {
      // caso tag seja 1
      case CONSTANT_Utf8:
        std::cout << "CONSTANT_UTF8_info"<< std::endl;
        std::cout << "\tLength:\t"<< std::dec << class_file.constant_pool[i].UTF8.size << std::endl;
        std::cout << "\tBytes:\t"<< class_file.constant_pool[i].UTF8.bytes << std::endl;
        break;
      // caso tag seja 3
      case CONSTANT_Integer:
        // representa o valor da constante int, em big-endian
        printf("CONSTANT_Integer\n");
        printf("Valor: %d\n", class_file.constant_pool[i].Integer.bytes);
        break;
      // caso tag seja 4
      case CONSTANT_Float:
        printf("CONSTANT_Float\n");
        float valor_f;
        memcpy(&valor_f, &(class_file.constant_pool[i].Float.bytes),
              sizeof(float));
        // representa o valor da constante float, em big-endian, no formato
        // IEEE-754
        printf("Float: %lf\n", valor_f);
        break;
      // caso tag seja 5
      case CONSTANT_Long:
        printf("CONSTANT_Long\n");
        // representa uma constante inteira de 8 bytes em big-endian
        // unsigned
        std::cout << "\tHigh:\t0x" << std::hex << class_file.constant_pool[i].Long.high_bytes << std::endl;
        // printf("\tHigh: 0x%0x\n", class_file.constant_pool[i].Long.high_bytes);
        printf("\tLow: 0x%0x\n", class_file.constant_pool[i].Long.low_bytes);
        long read_long_value;
        memcpy(&read_long_value, &(class_file.constant_pool[i].Long.high_bytes),
              sizeof(long));
        memcpy(&read_long_value, &(class_file.constant_pool[i].Long.low_bytes),
              sizeof(long));
        // ((long) high_bytes << 32) + low_bytes
        printf("\tLong Value: %ld\n", read_long_value);
        break;
      // caso tag seja 6
      case CONSTANT_Double:
        printf("CONSTANT_Double\n");

        std::cout << "\tHigh:\t0x"<< std::hex << class_file.constant_pool[i].Double.high_bytes << std::endl;
        std::cout << "\tLow:\t0x"<< std::hex << class_file.constant_pool[i].Double.low_bytes << std::endl;

        double read_double_value;
        u8 aux;
        // representa uma constante de ponto flutuante de 8 bytes em big-endian
        // no formato IEEE-754
        aux = ((u8)class_file.constant_pool[i].Double.high_bytes << 32) | class_file.constant_pool[i].Double.low_bytes;
        memcpy(&read_double_value, &aux, sizeof(double));

        std::cout << "\tDouble Value:\t"<< read_double_value << std::endl;
        break;
      // caso tag seja 7
      case CONSTANT_Class :
        std::cout << "CONSTANT_Class_info" << std::endl;

        std::cout << "\tName index:\t#" << std::dec << class_file.constant_pool[i].Class.type_class_info << std::endl;
        // exibe nome de uma classe ou interface
        std::cout << "\tClass name:\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                            class_file.constant_pool[i].Class.type_class_info - 1) << std::endl;
      break;
      // caso tag seja 8
      case CONSTANT_String:
        std::cout << "CONSTANT_String" << std::endl;

        // representa sequência de caracteres com a qual o objeto String será
        // iniciado
        std::cout << "\tString:\t#" << std::dec << class_file.constant_pool[i].String.bytes;
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                              class_file.constant_pool[i].String.bytes-1) << std::endl;
        break;
      // caso tag seja 9
      case CONSTANT_Fieldref:
        std::cout << "CONSTANT_Fieldref" << std::endl;

        // representa nome completo da classe ou interface que contem
        // a declaração desse field
        std::cout << "\tClass index:\t#" << std::dec << class_file.constant_pool[i].FieldRef.class_index;
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                          class_file.constant_pool[i].FieldRef.class_index-1) << std::endl;

        // representa um field ou método sem indicar classe ou interface
        // a que pertence
        std::cout << "\tName and Type:\t#" << std::dec << class_file.constant_pool[i].FieldRef.name_and_type_index;
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                  class_file.constant_pool[i].FieldRef.name_and_type_index-1) << std::endl;
        break;
      // caso tag seja 10
      case CONSTANT_Methodref:
        std::cout << "CONSTANT_Methodref"<< std::endl;

        // representa um método
        std::cout << "\tClass index:\t#"<< class_file.constant_pool[i].MethodRef.index;
        // representa nome completo classe que contem a declaração desse método
        std::cout << " \t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                              class_file.constant_pool[i].MethodRef.index-1);
        std::cout << std::endl;


        std::cout << "\tName and Type:\t#"<< class_file.constant_pool[i].MethodRef.name_and_type;
        // indica nome e descritor do método
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                        class_file.constant_pool[i].MethodRef.name_and_type-1);
        std::cout << std::endl;
        break;
      // caso tag seja 11
      case CONSTANT_InterfaceMethodref:
        std::cout << "CONSTANT_InterfaceMethodref"<< std::endl;

        // representa nome completo da interface que contem a declaração desse
        // método
        std::cout << "Index:"<< std::endl;
        std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                      class_file.constant_pool[i].InterfaceMethodRef.index-1)<< std::endl;

        // indica nome e descritor do método
        std::cout << "Name and Type:"<< std::endl;
        std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
              class_file.constant_pool[i].InterfaceMethodRef.name_and_type-1);
        break;
      // caso tag seja 12
      case CONSTANT_NameAndType:
        std::cout << "CONSTANT_NameAndType:"<< std::endl;

        // printf("Name index: ");
        std::cout << "\tName:\t\t#"<< class_file.constant_pool[i].NameAndType.name_index;
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                        class_file.constant_pool[i].NameAndType.name_index-1) << std::endl;
        // printf("\nDescriptor index: ");
        std::cout << "\tDescriptor:\t#"<< class_file.constant_pool[i].NameAndType.descriptor_index;
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                  class_file.constant_pool[i].NameAndType.descriptor_index-1) << std::endl;
        break;
      case CONSTANT_EmptySpace:
        std::cout << "\tLarge numeric continued / empty item"<< std::endl;
        break;
      default:
        printf("Tag %d. Wrong tag number. Shutting down.\n",
                class_file.constant_pool[i].tag);
        exit(1);
    }
    printf("\n");
  }
}

/** @brief Printa as interfaces contidas no .class
 *  @param class_file
 *  @return void
 */
// void ClassFilePrinter::print_interfaces(JavaClass class_file) {
//   int i;

//   if (class_file.interface_count != 0) {
//     for(i = 0; i < class_file.interface_count; i++) {
//       int index = class_file.constant_pool[class_file.interfaces[i] - 1].Class.type_class_info;

//       printf("\tInterface %d:     cp_info_#%d   %d", i, class_file.interfaces[i], index);
//       // READ UTF 8
//       printf("\n");
//     }
//   }
// }

// /*  @brief Printa os fields contidos no .class
//  *  @param class_file
//  *  @return void
//  */
// void ClassFilePrinter::print_fields_info(JavaClass class_file) {
//   int i, j;
//
//   if (class_file.field_count != 0) {
//     for (i = 0; i < class_file.field_count; i++) {
//       printf("\tName:             cp_info_#%d \n", class_file.fields[i].type_class_info);
//       printf("\tDescriptor:       cp_info_#%d \n", class_file.fields[i].descriptor_index);
//       printf("\tAccess Flag:      0x%04X      \n", class_file.fields[i].access_flag);
//       printf("\tAttributes count: %d        \n\n", class_file.fields[i].atributes_count);
//
//       for (j = 0; j < class_file.fields[i].atributes_count; j++) {
//         printf("\tGeneric Info\n");
//         printf("\t\tattribute_type_class_info:     cp_info_#%d\n", class_file.fields[i].attributes->attribute_type_class_info);
//         printf("\t\tattribute_length:         %u        \n\n", class_file.fields[i].attributes->attribute_length);
//         printf("\tSpecific Info:\n");
//         printf("\t\tconstant_value_index:     cp_info_#%d\n", class_file.fields[i].attributes->constant_value_index - 1);
//         printf("\n\n\n");
//       }
//     }
//   }
// }