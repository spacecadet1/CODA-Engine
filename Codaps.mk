
Codaps.dll: dlldata.obj Coda_p.obj Coda_i.obj
	link /dll /out:Codaps.dll /def:Codaps.def /entry:DllMain dlldata.obj Coda_p.obj Coda_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del Codaps.dll
	@del Codaps.lib
	@del Codaps.exp
	@del dlldata.obj
	@del Coda_p.obj
	@del Coda_i.obj
