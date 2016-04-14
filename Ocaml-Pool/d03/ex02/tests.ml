let () =
	print_endline "Test with [rot42 'abcdefghijklmnopqrstuvwxyz']: ";
	print_endline (Cipher.rot42 "abcdefghijklmnopqrstuvwxyz");
	print_char '\n';

	print_endline "Test with [unrot42 (rot42 'abcdefghijklmnopqrstuvwxyz')]: ";
	print_endline (Uncipher.unrot42 (Cipher.rot42 "abcdefghijklmnopqrstuvwxyz"));
	print_char '\n';

	print_endline "Test with [caesar 'abcdefghijklmnopqrstuvwxyz' 1]: ";
	print_endline (Cipher.caesar 1 "abcdefghijklmnopqrstuvwxyz");
	print_char '\n';

	print_endline "Test with [uncaesar (caesar 'abcdefghijklmnopqrstuvwxyz' 1) 1]: ";
	print_endline (Uncipher.uncaesar 1 (Cipher.caesar 1 "abcdefghijklmnopqrstuvwxyz"));
	print_char '\n';

	print_endline "Test with [xor 1 'abcdefghijklmnopqrstuvwxyz']: ";
	print_endline (Cipher.xor 1 "abcdefghijklmnopqrstuvwxyz");
	print_char '\n';

	print_endline "Test with [xor 1 (xor 1 'abcdefghijklmnopqrstuvwxyz')]: ";
	print_endline (Cipher.xor 1 (Cipher.xor 1 "abcdefghijklmnopqrstuvwxyz"));
	print_char '\n';

	print_endline "Test with [ft_uncrypt (ft_crypt 'abcdefghijklmnopqrstuvwxyz' [rcaesar 1;xor 2]) [uncaesar 1;xor 2]: ";
	print_endline (Uncipher.ft_uncrypt (Cipher.ft_crypt "abcdefghijklmnopqrstuvwxyz" [Cipher.caesar 1;Cipher.xor 2]) [Uncipher.uncaesar 1;Cipher.xor 2]);
