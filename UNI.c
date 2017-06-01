unsigned char    *unicode(wchar_t c)
{
    unsigned char    *str;
    int                bytes;
    int                i;

    if (c < 0)
        return (NULL);
    bytes = (c < 128) ? 1 : 4;
    bytes = (c > 127 && c < 2048) ? 2 : bytes;
    bytes = (c > 2047 && c < 65536) ? 3 : bytes;
    if (!(str = (unsigned char*)malloc(sizeof(unsigned char) * (bytes + 1))))
        return (NULL);
    i = -1;
    str[bytes] = '\0';
    if (bytes == 1)
        str[0] = c;
    else
        while (++i < bytes)
            if (i == 0)
                str[i] = (c >> ((bytes - 1) * 6)) + 192 +
                    ((bytes > 2) ? 32 : 0) + ((bytes == 4) ? 16 : 0);
            else
                str[i] = ((c >> ((bytes - i - 1) * 6)) & 63) + 128;
    return (str);
}
