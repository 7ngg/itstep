import { User } from "@/components/profile";
import AsyncStorage from "@react-native-async-storage/async-storage";
import React, { useEffect, useState } from "react";
import { Pressable, ScrollView, StyleSheet, Text, View } from "react-native";
import { SafeAreaView } from "react-native-safe-area-context";
import { globalStyles } from "../global-styles";
import { useRouter } from "expo-router";

export default function Users() {
  const [users, setUsers] = useState<User[]>([]);

  const router = useRouter();

  useEffect(() => {
    const fetchUser = async () => {
      const token = await AsyncStorage.getItem("accessToken");
      const res = await fetch("http://192.168.100.3:8080/users", {
        headers: {
          Authorization: `Bearer ${token}`,
        },
      });

      const data = await res.json();

      if (!res.ok) {
        return;
      }

      setUsers(data);
    };

    fetchUser();
  }, []);

  return (
    <SafeAreaView style={styles.container}>
      <ScrollView
        contentContainerStyle={{
          gap: 8,
        }}
      >
        {users.map((u, i) => {
          return (
            <View key={i} style={styles.card}>
              <Text>{u.username}</Text>
              <Text>{u.memberForDays}</Text>
            </View>
          );
        })}
      </ScrollView>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    backgroundColor: globalStyles.background,
    height: "100%",
    justifyContent: "space-between",
    paddingHorizontal: 16,
    paddingVertical: 32,
  },
  card: {
    backgroundColor: globalStyles.backgroundLighter,
    flexDirection: "row",
    justifyContent: "space-between",
    paddingHorizontal: 12,
    paddingVertical: 16,
    borderRadius: 10,
  },
});
