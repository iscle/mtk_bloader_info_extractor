# mtk_bloader_info_extractor

This is a simple tool to extract information from MediaTek preloader images. It was developed in order to extract memory timings and other emigen data from prebuilt preloaders in order to create new source code.

Tested with Coolpad C558.

## Usage

```
$ ./mtk_bloader_info_extractor preloader.bin
```

Use `-e` to print the output in a format that can be copied to the emigen spreadsheet.
