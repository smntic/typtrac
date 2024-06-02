def convert_file_to_header(input_filename, output_header_filename, array_name):
    with open(input_filename, 'r') as infile, open(output_header_filename, 'w') as outfile:
        outfile.write(f'#ifndef TYPTRAC_{array_name.upper()}_H\n')
        outfile.write(f'#define TYPTRAC_{array_name.upper()}_H\n\n')

        outfile.write(f'static const char* {array_name.upper()}[] = {{\n')

        n_lines = 0;
        for line in infile:
            clean_line = line.strip().replace('"', '\\"')
            outfile.write(f'    "{clean_line}",\n')
            n_lines += 1

        outfile.write(f'}};\n\n')
        outfile.write(f'static const int {array_name.upper()}_SIZE = {n_lines};\n\n')
        outfile.write(f'#endif // TYPTRAC_{array_name.upper()}_H\n')

if __name__ == "__main__":
    convert_file_to_header('../assets/english1k.txt', '../include/languages/english1k.h', 'english1k')

