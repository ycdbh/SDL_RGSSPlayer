#include "pch.h"
#include "rsm_Font.h"

RSM_Font::RSM_Font(const char* filename, int size)
{
	_filename = filename;
	_size = size;
	_font = TTF_OpenFont(_filename, _size);
}

RSM_Font::~RSM_Font()
{
	TTF_CloseFont(_font);
	_font = NULL;
	_size = 0;
}

const char *RSM_Font::name(const char* filename)
{
	if (!filename) {
		return _filename;
	}
	TTF_CloseFont(_font);
	_filename = filename;
	_font = TTF_OpenFont(_filename, _size);
	return NULL;
}

int RSM_Font::size(int size)
{
	if (size == -1) {
		return _size;
	}
	TTF_CloseFont(_font);
	_size = size;
	_font = TTF_OpenFont(_filename, _size);
	return 0;
}
