const std = @import("std");

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // Executables
    const exes_step = b.step("exes", "Build executables");

    inline for (PATHS) |PATH| {
        const exe = b.addExecutable(.{
            .name = std.fs.path.basename(PATH),
            .target = target,
            .optimize = optimize,
        });
        exe.addCSourceFiles(.{ .files = &.{"src/" ++ PATH ++ ".cpp"}, .flags = &.{"-std=c++20"} });
        exe.linkLibCpp();

        const exe_install = b.addInstallArtifact(exe, .{ .dest_dir = .{ .override = .{ .custom = std.fs.path.dirname(PATH).? } } });
        exes_step.dependOn(&exe_install.step);
    }

    b.default_step.dependOn(exes_step);
}

const PATHS = &.{
    "1-testing/a_conditioner",
    "1-testing/b_triangle",
    "1-testing/c_phone_numbers",
    "1-testing/d_root_equation",
    "1-testing/e_ambulance",
    "1-testing/f_laptops_placement",
    "1-testing/g_workpieces",
    "1-testing/h_metro",
    "1-testing/i_prisoner_of_if_castle",
    "1-testing/j_system_of_linear_equations",
    "2-linear-search/a_does_the_list_increase",
    "2-linear-search/b_establish_sequence_type",
    "2-linear-search/c_closest_number",
    "2-linear-search/d_larger_than_neighbours",
    "2-linear-search/e_cowpat_throwing_championship",
    "2-linear-search/f_symmetric_sequence",
    "2-linear-search/g_maximum_pairwise_product",
    "2-linear-search/h_maximum_triplewise_product",
    "2-linear-search/i_minesweeper",
    "2-linear-search/j_maxims_triangle",
    "3-sets/a_number_of_unique_integers",
    "3-sets/b_intersection_of_sets",
    "3-sets/c_cubes",
    "3-sets/d_number_of_words_in_text",
    "3-sets/e_open_calculator",
    "3-sets/f_alien_genome",
    "3-sets/g_tortoises",
    "3-sets/h_angry_pigs",
    "3-sets/i_polyglots",
    "3-sets/j_jogging_across_manhattan",
    "4-maps/a_synonym_dictionary",
    "4-maps/b_order_number_of_word_appearance",
    "4-maps/c_most_frequent_word",
    "4-maps/d_keyboard",
    "4-maps/e_pyramid",
    "4-maps/f_sales",
    "4-maps/g_bank_accounts",
    "4-maps/h_decyphering_mayan_writing",
    "4-maps/i_emphasis_test",
    "4-maps/j_additional_plagiarism_test",
    "5-prefix-sums/a_stylish_clothes",
    "5-prefix-sums/b_sum_of_numberplates",
    "5-prefix-sums/c_tourism",
    "5-prefix-sums/d_city_che",
    "5-prefix-sums/e_beauty_above_all",
    "5-prefix-sums/f_conditioners",
    "5-prefix-sums/g_hypercheckers_score",
    "5-prefix-sums/h_substring",
    "5-prefix-sums/i_robot",
    "5-prefix-sums/j_triangles",
    "6-binary-search/a_binary_search",
    "6-binary-search/b_approximate_binary_search",
    "6-binary-search/c_diplomas",
    "6-binary-search/d_space_settlement",
    "6-binary-search/e_improving_academic_performance",
    "6-binary-search/f_very_easy_task",
    "6-binary-search/g_area",
    "6-binary-search/h_wires",
    "6-binary-search/i_subbotnik",
    "6-binary-search/j_median_of_union",
    "6-binary-search/k_median_of_union_2",
    "7-event-sorting/a_student_supervision",
    "7-event-sorting/b_points_and_segments",
    "7-event-sorting/c_auditorium_seating_arrangement",
    "7-event-sorting/d_advertisement",
    "7-event-sorting/e_ticket_windows",
    "7-event-sorting/f_contemporaries",
    "7-event-sorting/g_kids_party",
    "7-event-sorting/h_security",
    "7-event-sorting/i_buses",
    "7-event-sorting/j_imu_construction",
    "8-trees/a_tree_height",
    "8-trees/b_depth_of_inserted_elements",
    "8-trees/c_second_maximum",
    "8-trees/d_traversal",
    "8-trees/e_leaves_output",
    "8-trees/f_fork_nodes_output",
    "8-trees/g_branch_nodes_output",
    "8-trees/h_avl_balance_condition",
    "8-trees/i_pedigree_children_count",
    "8-trees/j_pedigree_level_count",
};
