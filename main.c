#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static long read_element(char *bloader_info_start, char print_type) {
    long cur_pos = 0;

    unsigned int sub_version;
    memcpy(&sub_version, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int type;
    memcpy(&type, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int emmc_id_len;
    memcpy(&emmc_id_len, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int fw_id_len;
    memcpy(&fw_id_len, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned char emmc_id[16];
    memcpy(emmc_id, bloader_info_start + cur_pos, 16);
    cur_pos += 16;

    unsigned char fw_id[8];
    memcpy(fw_id, bloader_info_start + cur_pos, 8);
    cur_pos += 8;

    unsigned int emi_cona_val;
    memcpy(&emi_cona_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_drvctl0_val;
    memcpy(&dramc_drvctl0_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_drvctl1_val;
    memcpy(&dramc_drvctl1_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_actim_val;
    memcpy(&dramc_actim_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_gddr3ctl1_val;
    memcpy(&dramc_gddr3ctl1_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_conf1_val;
    memcpy(&dramc_conf1_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_ddr2ctl_val;
    memcpy(&dramc_ddr2ctl_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_test2_3_val;
    memcpy(&dramc_test2_3_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_conf2_val;
    memcpy(&dramc_conf2_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_pd_ctrl_val;
    memcpy(&dramc_pd_ctrl_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_padctl3_val;
    memcpy(&dramc_padctl3_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_dqodly_val;
    memcpy(&dramc_dqodly_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_addr_output_dly;
    memcpy(&dramc_addr_output_dly, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_clk_output_dly;
    memcpy(&dramc_clk_output_dly, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_actim1_val;
    memcpy(&dramc_actim1_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_misctl0_val;
    memcpy(&dramc_misctl0_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dramc_actim05t_val;
    memcpy(&dramc_actim05t_val, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int dram_rank_size[4];
    memcpy(dram_rank_size, bloader_info_start + cur_pos, 16);
    cur_pos += 16;

    unsigned int reserved[10];
    memcpy(reserved, bloader_info_start + cur_pos, 40);
    cur_pos += 40;

    unsigned int lpddr3_mode_reg1;
    memcpy(&lpddr3_mode_reg1, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int lpddr3_mode_reg2;
    memcpy(&lpddr3_mode_reg2, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int lpddr3_mode_reg3;
    memcpy(&lpddr3_mode_reg3, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int lpddr3_mode_reg5;
    memcpy(&lpddr3_mode_reg5, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int lpddr3_mode_reg10;
    memcpy(&lpddr3_mode_reg10, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    unsigned int lpddr3_mode_reg63;
    memcpy(&lpddr3_mode_reg63, bloader_info_start + cur_pos, 4);
    cur_pos += 4;

    if (print_type == 1) {
        printf("type: 0x%X\n", type);
        if (emmc_id_len > 0) {
            printf("0x");
            for (int i = 0; i < emmc_id_len; i++) {
                printf("%02X", emmc_id[i]);
            }
        }
        printf("\t");
        if (fw_id_len > 0) {
            printf("0x");
            for (int i = 0; i < fw_id_len; i++) {
                printf("%02X", fw_id[i]);
            }
        }
        printf("\t");
        printf("\t"); // Nand Page Size (B)
        printf("0x%08X\t", emi_cona_val);
        printf("0x%08X\t", dramc_drvctl0_val);
        printf("0x%08X\t", dramc_drvctl1_val);
        printf("0x%08X\t", dramc_actim_val);
        printf("0x%08X\t", dramc_gddr3ctl1_val);
        printf("0x%08X\t", dramc_conf1_val);
        printf("0x%08X\t", dramc_ddr2ctl_val);
        printf("0x%08X\t", dramc_test2_3_val);
        printf("0x%08X\t", dramc_conf2_val);
        printf("0x%08X\t", dramc_pd_ctrl_val);
        printf("0x%08X\t", dramc_padctl3_val);
        printf("0x%08X\t", dramc_dqodly_val);
        printf("0x%08X\t", dramc_addr_output_dly);
        printf("0x%08X\t", dramc_clk_output_dly);
        printf("0x%08X\t", dramc_actim1_val);
        printf("0x%08X\t", dramc_misctl0_val);
        printf("0x%08X\t", dramc_actim05t_val);
        printf("LPDDR3\t");
        printf("0x%08X\t", lpddr3_mode_reg1);
        printf("0x%08X\t", lpddr3_mode_reg2);
        printf("0x%08X\t", lpddr3_mode_reg3);
        printf("0x%08X\t", lpddr3_mode_reg5);
        printf("0x%08X\t", lpddr3_mode_reg10);
        printf("0x%08X\n", lpddr3_mode_reg63);
    } else {
        printf("type: 0x%X\n", type);
        if (emmc_id_len > 0) {
            printf("emmc_id: 0x");
            for (int i = 0; i < emmc_id_len; i++) {
                printf("%02X", emmc_id[i]);
            }
            printf("\n");
        }
        if (fw_id_len > 0) {
            printf("fw_id: 0x");
            for (int i = 0; i < fw_id_len; i++) {
                printf("%02X", fw_id[i]);
            }
            printf("\n");
        }
        printf("emi_cona_val: 0x%08X\n", emi_cona_val);
        printf("dramc_drvctl0_val: 0x%08X\n", dramc_drvctl0_val);
        printf("dramc_drvctl1_val: 0x%08X\n", dramc_drvctl1_val);
        printf("dramc_actim_val: 0x%08X\n", dramc_actim_val);
        printf("dramc_gddr3ctl1_val: 0x%08X\n", dramc_gddr3ctl1_val);
        printf("dramc_conf1_val: 0x%08X\n", dramc_conf1_val);
        printf("dramc_ddr2ctl_val: 0x%08X\n", dramc_ddr2ctl_val);
        printf("dramc_test2_3_val: 0x%08X\n", dramc_test2_3_val);
        printf("dramc_conf2_val: 0x%08X\n", dramc_conf2_val);
        printf("dramc_pd_ctrl_val: 0x%08X\n", dramc_pd_ctrl_val);
        printf("dramc_padctl3_val: 0x%08X\n", dramc_padctl3_val);
        printf("dramc_dqodly_val: 0x%08X\n", dramc_dqodly_val);
        printf("dramc_addr_output_dly: 0x%08X\n", dramc_addr_output_dly);
        printf("dramc_clk_output_dly: 0x%08X\n", dramc_clk_output_dly);
        printf("dramc_actim1_val: 0x%08X\n", dramc_actim1_val);
        printf("dramc_misctl0_val: 0x%08X\n", dramc_misctl0_val);
        printf("dramc_actim05t_val: 0x%08X\n", dramc_actim05t_val);
        //printf("dram_rank_size: 0x%08X, 0x%08X, 0x%08X, 0x%08X\n",
        //       dram_rank_size[0], dram_rank_size[1], dram_rank_size[2], dram_rank_size[3]);
        //printf("reserved: %d\n", reserved);
        printf("lpddr3_mode_reg1: 0x%08X\n", lpddr3_mode_reg1);
        printf("lpddr3_mode_reg2: 0x%08X\n", lpddr3_mode_reg2);
        printf("lpddr3_mode_reg3: 0x%08X\n", lpddr3_mode_reg3);
        printf("lpddr3_mode_reg5: 0x%08X\n", lpddr3_mode_reg5);
        printf("lpddr3_mode_reg10: 0x%08X\n", lpddr3_mode_reg10);
        printf("lpddr3_mode_reg63: 0x%08X\n", lpddr3_mode_reg63);
    }

    return cur_pos;
}

static void parse(char *buf, char print_type) {
    long cur_pos = 0;

    char header[27];
    memcpy(header, buf + cur_pos, 27);
    cur_pos += 27;

    char pre_bin[61];
    memcpy(pre_bin, buf + cur_pos, 61);
    cur_pos += 61;

    unsigned int hex_1;
    memcpy(&hex_1, buf + cur_pos, 4);
    cur_pos += 4;

    unsigned int hex_2;
    memcpy(&hex_2, buf + cur_pos, 4);
    cur_pos += 4;

    unsigned int hex_3;
    memcpy(&hex_3, buf + cur_pos, 4);
    cur_pos += 4;

    char mtk_bin[8];
    memcpy(mtk_bin, buf + cur_pos, 8);
    cur_pos += 8;

    unsigned int total_custem_chips;
    memcpy(&total_custem_chips, buf + cur_pos, 4);
    cur_pos += 4;

    printf("header: %s\n", header);
    printf("pre_bin: %s\n", pre_bin);
    printf("hex_1: 0x%X\n", hex_1);
    printf("hex_2: 0x%X\n", hex_2);
    printf("hex_3: 0x%X\n", hex_3);
    printf("mtk_bin: %s\n", mtk_bin);
    printf("total_custem_chips: %d\n\n", total_custem_chips);

    int i;
    for (i = 0; i < total_custem_chips; i++) {
        printf("--------Start element %d--------\n", i);
        cur_pos += read_element(buf + cur_pos, print_type);
        printf("--------End element %d--------\n\n", i);
    }

    unsigned int size;
    memcpy(&size, buf + cur_pos, 4);
    cur_pos += 4;

    printf("size: %d\n", size);
}

static long get_file_size(FILE *f) {
    long cur = ftell(f);

    fseek(f, 0L, SEEK_END);
    long size = ftell(f);
    fseek(f, cur, SEEK_SET);

    return size;
}

static void usage(void) {
    printf("./mtk_bloader_info_extractor [-e] <filename>\n");
    printf("\t-e: Print in excel format\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        usage();
        return 1;
    }

    char print_type = 0;

    for (int i = 1; i < argc - 1; i++) {
        if (!strcmp(argv[i], "-e")) {
            print_type = 1;
        }
    }

    char *filename = argv[argc - 1];
    printf("Using preloader \"%s\"\n", filename);

    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error: Could not open preloader file!\n");
        return 1;
    }

    long file_size = get_file_size(f);
    char *buf = malloc(file_size);
    if (buf == NULL) {
        printf("Error: Failed to allocate memory for preloader!\n");
        fclose(f);
        return 1;
    }

    fread(buf, sizeof(char), file_size, f);
    if (ferror(f)) {
        printf("Error: Failed to copy preloader contents!\n");
        fclose(f);
        free(buf);
        return 1;
    }

    fclose(f);

    char *bloader_info_start = memmem(buf, file_size, "MTK_BLOADER_INFO", strlen("MTK_BLOADER_INFO"));
    if (bloader_info_start == NULL) {
        printf("Error: Could not find MTK_BLOADER_INFO header!\n");
        free(buf);
        return 1;
    }

    printf("Found MTK_BLOADER_INFO header at offset 0x%lX!\n", bloader_info_start - buf);
    parse(bloader_info_start, print_type);

    free(buf);
    return 0;
}
