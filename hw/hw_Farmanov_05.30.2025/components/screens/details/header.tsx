import { router } from "expo-router";
import { ArrowLeft, InfoCircle } from "iconsax-react-native";
import { View, Text, StyleSheet } from "react-native";

const Header = () => {
  return (
    <View
      style={{
        paddingHorizontal: 24,
        paddingTop: 8,
      }}
    >
      <View style={styles.header}>
        <View style={styles.headerCircle}>
          <View style={styles.headerIcon}>
            <ArrowLeft
              size={24}
              color="white"
              onPress={() => {
                router.back();
              }}
            />
          </View>
        </View>
        <View style={styles.headerCircle}>
          <View style={styles.headerIcon}>
            <InfoCircle size={24} color="white" />
          </View>
        </View>
      </View>
    </View>
  );
};

export default Header;

const styles = StyleSheet.create({
  header: {
    flexDirection: "row",
    justifyContent: "space-between",
  },
  headerCircle: {
    flexDirection: "row",
    alignItems: "center",
    gap: 5,
  },
  headerIcon: {
    padding: 14,
    borderColor: "rgba(255, 255, 255, 0.07)",
    borderWidth: 1,
    flexGrow: 0,
    borderRadius: 100,
    borderStyle: "solid",
  },
});
