{ pkgs }: {
	deps = [
		pkgs.t
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}