CODES = {
  '!' => '-.-.--',
  '"' => '.-..-.',
  '$' => '...-..-',
  '&' => '.-...',
  "'" => '.----.',
  '(' => '-.--.',
  ')' => '-.--.-',
  '+' => '.-.-.',
  ',' => '--..--',
  '-' => '-....-',
  '.' => '.-.-.-',
  '/' => '-..-.',
  '0' => '-----',
  '1' => '.----',
  '2' => '..---',
  '3' => '...--',
  '4' => '....-',
  '5' => '.....',
  '6' => '-....',
  '7' => '--...',
  '8' => '---..',
  '9' => '----.',
  ':' => '---...',
  ';' => '-.-.-.',
  '=' => '-...-',
  '?' => '..--..',
  '@' => '.--.-.',
  'A' => '.-',
  'B' => '-...',
  'C' => '-.-.',
  'D' => '-..',
  'E' => '.',
  'F' => '..-.',
  'G' => '--.',
  'H' => '....',
  'I' => '..',
  'J' => '.---',
  'K' => '-.-',
  'L' => '.-..',
  'M' => '--',
  'N' => '-.',
  'O' => '---',
  'P' => '.--.',
  'Q' => '--.-',
  'R' => '.-.',
  'S' => '...',
  'T' => '-',
  'U' => '..-',
  'V' => '...-',
  'W' => '.--',
  'X' => '-..-',
  'Y' => '-.--',
  'Z' => '--..',
  '_' => '..--.-',
  '`' => '.----.',
}

puts <<EOF
/* -*- c -*- */
#include <stdint.h>

static const uint8_t __morse_nil[] = { 0 }; /* no code */
static const uint8_t __morse_20[] = { 4, 0, 0, 0, 0 }; /* space */
EOF

morse_t = ['__morse_20']

mlen = 0

('!'..'z').each do |char|
  code = CODES[char.upcase]
  var = "__morse_#{char.ord}"
  points = []
  code.to_s.each_char do |ch|
    if ch == '.'
      points << "255"
      points << "0"
    elsif ch == '-'
      points << "255"
      points << "255"
      points << "255"
      points << "0"
    else
      raise "Unknown code #{ch.inspect}"
    end
  end
  points.pop
  puts "static const uint8_t #{var}[] = { #{points.size}, #{points.join(', ')} }; /* #{char} #{code} */"
  morse_t << var
  mlen = points.size if mlen < points.size
end

puts "static const uint8_t* morse_t[] = {\n    #{morse_t.join(",\n    ")}};"

STDERR.puts mlen
